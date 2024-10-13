#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
#include "health.h"
#include "abilities.h"
#include "weapons.h"

namespace seneca {
    /// Template types:
    ///     - T:                    The type of the object storing the health. This type is passed to the base class (CharacterTpl).
    ///     - FirstAbility_t:       The type implementing the first special ability that this rogue has (e.g., Fireball, Healing, etc.).
    ///     - SecondAbility_t:      The type implementing the second special ability that this rogue has (e.g., Fireball, Healing, etc.).
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : public CharacterTpl<T> {
        /// <summary>
        ///     A number representing the basic defense of this character
        /// </summary>
        int m_baseDefense;
        
        /// <summary>
        ///     A number representing the basic attack power of this character
        /// </summary>
        int m_baseAttack;
        
        /// <summary>
        ///     An object of type Ability_t representing the first special ability of this character.
        /// </summary>
        FirstAbility_t m_firstAbility;
        
        /// <summary>
        ///     An object of type Ability_t representing the second special ability of this character.
        /// </summary>
        SecondAbility_t m_secondAbility;
        
        /// <summary>
        ///     A weapon of type dagger.
        /// </summary>
        Dagger m_weapon;
        
    public:
        /// <summary>
        ///     Initializes a new object to the values received as parameters.
        /// </summary>
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);
        
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

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
        : CharacterTpl<T>(name, healthMax),
        m_baseAttack(baseAttack),
        m_baseDefense(baseDefense),
        m_firstAbility(),
        m_secondAbility(),
        m_weapon() {}

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
        return static_cast<int>(m_baseAttack + (2 * static_cast<double>(m_weapon)));
    }

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
        return m_baseDefense;
    }

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Character* Rogue <T, FirstAbility_t, SecondAbility_t>::clone() const {
        return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);
    }
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
        m_firstAbility.useAbility(this);
        m_secondAbility.useAbility(this);
        int dmg = this->getAttackAmnt();
        std::cout << "Rogue deals " << dmg << " melee damage!" << std::endl;
        enemy->takeDamage(dmg);
    }
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {
        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
        std::cout << "\tRogue has a defense of " << this->getDefenseAmnt() << ". Reducing damage received." << std::endl;
        int dmgReceived = dmg - this->getDefenseAmnt();
        if (dmgReceived < 0)
            dmgReceived = 0;
        m_firstAbility.transformDamageReceived(dmgReceived);
        m_secondAbility.transformDamageReceived(dmgReceived);
        this->CharacterTpl<T>::takeDamage(dmgReceived);
    }

#include "rogue.h"
}
#endif /* SENECA_ROGUE_H */
