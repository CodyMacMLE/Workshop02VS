#include <string>
#include "barbarian.h"
#include "characterTpl.h"
#include "character.h"
#include "weapons.h"

namespace seneca {
    /// <summary>
    ///     Initializes a new object to the values received as parameters.
    /// </summary>
    Barbarian::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
		: CharacterTpl(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense), m_weapon(primaryWeapon, secondaryWeapon) {
	}

    /// <summary>
    ///     Returns the damage that character can do in an attack
    /// </summary>
    int Barbarian::getAttackAmnt() const {
        return -1;
    }

    /// <summary>
    ///     Return the base defense value.
    /// </summary>
	int Barbarian::getDefenseAmnt() const {
		return -1;
	}

    /// <summary>
    ///     Dynamically creates a copy of the current instance and returns its address to the client.
    /// </summary>
    Character* Barbarian::clone() const {
		return nullptr;
    }

    /// <summary>
    ///     Attacks the enemy received as parameter and inflicts damage to it.
    /// </summary>
    void Barbarian::attack(Character* enemy) {

    }

    /// <summary>
    ///     Some other character inflicts damage to the current barbarian in the amount specified as
    ///     parameter. This function will modify the damage received using the defense capabilities and
    ///     the special ability, before calling the base class member to update the health.
    /// </summary>
    void Barbarian::takeDamage(int dmg) {

    }
}