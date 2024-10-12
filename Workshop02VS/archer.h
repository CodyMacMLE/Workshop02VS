//
//  archer.h
//  Workshop02
//
//  Created by Cody MacDonald on 2024-10-11.
//
#include "characterTpl.h"
#include "character.h"
#include "health.h"

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

namespace seneca {
    /// Template types:
    ///     - Weapon_t:     The type implementing the weapons the archer will handle
    ///         (e.g., Sword, Bow, etc.).
    template<typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
        /// <summary>
        ///     A number representing the basic defense of this character
        /// </summary>
        int m_baseDefense;
        
        /// <summary>
        ///     A number representing the basic attack power of this character
        /// </summary>
        int m_baseAttack;
        
        /// <summary>
        ///     An array of two objects of type Weapon_t, representing the two weapons the character can
        ///     use in battle.
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
}
#endif /* SENECA_ARCHER_H */
