#include <iostream>
#include <string>
#include "barbarian.h"
#include "characterTpl.h"
#include "character.h"
#include "weapons.h"

namespace seneca {

    template <typename T, typename Ability_t, typename Weapon_t>
    Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) :
        CharacterTpl<T>(name, healthMax) {
        m_baseAttack = baseAttack;
		m_baseDefense = baseDefense;
		m_ability = Ability_t();
		m_weapon[0] = primaryWeapon;
		m_weapon[1] = secondaryWeapon;
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
		return m_baseAttack + (static_cast<double>(m_weapon[0]) / 2) + (static_cast<double>(m_weapon[1]) / 2);
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const {
        return m_baseDefense
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
		return new Barbarian<T, Ability_t, Weapon_t>(*this);
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {
        std::cout << this.getName() << " is attacking " << enemy.getName() << "." << std::endl;
		m_ability.useAbility(this);
		int dmg = this->getAttackAmnt();
		m_ability.transformDamageDealt(dmg);
		std::cout << "Barbarian deals " << dmg << " melee damage!" << std::endl;
		enemy->takeDamage(dmg);
    }

    template <typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {
		std::cout << this.getName() << " is attacked for " << dmg << " damage." << std::endl;
		std::cout << "\tBarbarian has a defense of " << this.getDefenseAmnt() << ". Reducing damage received." << std::endl;
		int dmgReceived = dmg - this.getDefenseAmnt();
		if (dmgReceived < 0)
			dmgReceived = 0;
        m_ability.transformDamageReceived(dmgReceived);
		this->CharacterTpl<T>::takeDamage(dmgReceived);
     }
}