//
//  barbarian.h
//  Workshop02
//
//  Created by Cody MacDonald on 2024-10-10.
//

#include "characterTpl.h"
#include "character.h"

#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

namespace seneca {
    /// Template types:
    ///     - T:    The type of the object storing the health. This type is passed to the base class.
    ///     - Ability_t:    The type implementing the special abilities that this barbarian has
    ///         (e.g., Fireball, Healing, etc.).
    ///     - Weapon_t:     The type implementing the weapons the barbarian will handle
    ///         (e.g., Sword, Bow, etc.).
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
}
#endif /* Barbarian_h */
