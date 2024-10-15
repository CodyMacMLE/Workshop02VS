#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include <iostream>
#include "characterTpl.h"
#include "health.h"
#include "weapons.h"

namespace seneca {
    /// Template types:
    ///     - Weapon_t:     The type implementing the weapons the archer will handle (e.g., Sword, Bow, etc.).
    template<typename Weapon_t>
    class Archer : public CharacterTpl<SuperHealth> {
        /// <summary>
        ///     A number representing the basic defense of this character
        /// </summary>
        int m_baseDefense;
        
        /// <summary>
        ///     A number representing the basic attack power of this character
        /// </summary>
        int m_baseAttack;
        
        /// <summary>
        ///     An object of type Weapon_t, representing the weapon the character can use in battle.
        /// </summary>
        Weapon_t m_weapon;
        
    public:
        /// <summary>
        ///     initializes a new object to the values received as parameters
        /// </summary>
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);
        
        /// <summary>
        ///     returns the damage that character can do in an attack, using the formula:
        /// </summary>
        int getAttackAmnt() const;
        
        /// <summary>
        ///     return the defense of this archer, using the formula
        /// </summary>
        int getDefenseAmnt() const;
        
		/// <summary>
		/// dynamically creates a copy of the current instance and returns its address to the client.
		/// </summary>
		Character* clone() const;

        /// <summary>
        ///     dynamically creates a copy of the current instance and returns its address to the client.
        /// </summary>
        void attack(Character* enemy);
        
        /// <summary>
        ///     attacks the enemy received as parameter and inflicts damage to it.
        /// </summary>
        void takeDamage(int dmg);
    };
    template<typename Weapon_t>
    Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon) : 
        CharacterTpl<SuperHealth>(name, healthMax), m_baseDefense(baseDefense), m_baseAttack(baseAttack), m_weapon(weapon) {}

    template<typename Weapon_t>
    int Archer<Weapon_t>::getAttackAmnt() const {
        return static_cast<int>(1.3 * m_baseAttack);
    }

    template<typename Weapon_t>
    int Archer<Weapon_t>::getDefenseAmnt() const {
        return static_cast<int>(1.2 * m_baseDefense);
    }

    template<typename Weapon_t>
    Character* Archer<Weapon_t>::clone() const {
        return new Archer<Weapon_t>(this->getName().c_str(), this->getHealthMax(), m_baseAttack, m_baseDefense, m_weapon);
    }

    template<typename Weapon_t>
    void Archer<Weapon_t>::attack(Character* enemy) {
        std::cout << getName() << " is attacking " << enemy->getName() << "." << std::endl;
        int dmg = getAttackAmnt();
        std::cout << "Archer deals " << dmg << " ranged damage!" << std::endl;
        enemy->takeDamage(dmg);
    }

    template<typename Weapon_t>
    void Archer<Weapon_t>::takeDamage(int dmg) {
        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
        std::cout << "\tArcher has a defense of " << this->getDefenseAmnt() << ". Reducing damage received." << std::endl;
        int dmgReceived = dmg - this->getDefenseAmnt();
        if (dmgReceived < 0)
            dmgReceived = 0;
        this->CharacterTpl<seneca::SuperHealth>::takeDamage(dmgReceived);
    }
}
#endif /* SENECA_ARCHER_H */
