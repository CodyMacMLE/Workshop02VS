#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include "character.h"
#include "characterTpl.h"
#include "health.h"
#include "abilities.h"
#include "weapons.h"

namespace seneca {
    /// Template types:
    ///     - T:            The type of the object storing the health. This type is passed to the base class.
    ///     - Ability_t:    The type implementing the special abilities that this barbarian has (e.g., Fireball, Healing, etc.).
    ///     - Weapon_t:     The type implementing the weapons the barbarian will handle (e.g., Sword, Bow, etc.).
    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T> {
        /// <summary>
        ///     A number representing the basic defense of this character
        /// </summary>
        int m_baseDefense;

        /// <summary>
        ///     A number representing the basic attack power of this character
        /// </summary>
        int m_baseAttack;

        /// <summary>
        ///     An object of type Ability_t representing the special ability of this character.
        /// </summary>
        Ability_t m_ability;

        /// <summary>
        ///     An array of two objects of type Weapon_t, representing the two weapons the character can
        ///     use in battle.
        /// </summary>
        Weapon_t m_weapon[2];

    public:
        /// <summary>
        ///     Initializes a new object to the values received as parameters.
        /// </summary>
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);

        /// <summary>
        ///     Returns the damage that character can do in an attack
        /// </summary>
        int getAttackAmnt() const;

        /// <summary>
        ///     Return the base defense value.
        /// </summary>
        int getDefenseAmnt() const;

        /// <summary>
        ///     Dynamically creates a copy of the current instance and returns its address to the client.
        /// </summary>
        Character* clone() const;

        /// <summary>
        ///     Attacks the enemy received as parameter and inflicts damage to it.
        /// </summary>
        void attack(Character* enemy);

        /// <summary>
        ///     Some other character inflicts damage to the current barbarian in the amount specified as
        ///     parameter. This function will modify the damage received using the defense capabilities and
        ///     the special ability, before calling the base class member to update the health.
        /// </summary>
        void takeDamage(int dmg);
    };

    template <typename T, typename Ability_t, typename Weapon_t>
    Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) 
        : CharacterTpl<T>(name, healthMax),
        m_baseAttack(baseAttack),
        m_baseDefense(baseDefense),
        m_ability() { 
        m_weapon[0] = primaryWeapon;
        m_weapon[1] = secondaryWeapon; 
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
        return m_baseAttack + (static_cast<double>(m_weapon[0]) / 2) + (static_cast<double>(m_weapon[1]) / 2);
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const {
        return m_baseDefense;
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
        return new Barbarian<T, Ability_t, Weapon_t>(*this);
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {
        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
        m_ability.useAbility(this);
        int dmg = this->getAttackAmnt();
        m_ability.transformDamageDealt(dmg);
        std::cout << "Barbarian deals " << dmg << " melee damage!" << std::endl;
        enemy->takeDamage(dmg);
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {
        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
        std::cout << "\tBarbarian has a defense of " << this->getDefenseAmnt() << ". Reducing damage received." << std::endl;
        int dmgReceived = dmg - this->getDefenseAmnt();
        if (dmgReceived < 0)
            dmgReceived = 0;
        m_ability.transformDamageReceived(dmgReceived);
        this->CharacterTpl<T>::takeDamage(dmgReceived);
    }
}
#endif /* Barbarian_h */
