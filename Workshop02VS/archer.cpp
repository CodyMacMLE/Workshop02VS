#include <iostream>
#include "archer.h"
#include "characterTpl.h"
#include "character.h"
#include "health.h"

namespace seneca {
	template<typename Weapon_t>
	Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon) 
		: CharacterTpl<seneca::SuperHealth> (name, healthMax) {
		m_baseDefense = baseDefense;
		m_baseAttack = baseAttack;
		m_weapon = weapon;
	}

	template<typename Weapon_t>
	int Archer<Weapon_t>::getAttackAmnt() const {
		return 1.2 * m_baseAttack;
	}

	template<typename Weapon_t>
	int Archer<Weapon_t>::getDefenseAmnt() const {
		return 1.2 * m_baseDefense;
	}

	template<typename Weapon_t>
	Character* Archer<Weapon_t>::clone() const {
		return new Archer<Weapon_t>(*this);
	}

	template<typename Weapon_t>
	void Archer<Weapon_t>::attack(Character* enemy) {
		return new Archer<Weapon_t>(*this);
	}

	template<typename Weapon_t>
	void Archer<Weapon_t>::takeDamage(int dmg) {
		std::cout << this.getName() << " is attacked for " << dmg << " damage." << std::endl;
		std::cout << "\tArcher has a defense of " << this.getDefenseAmnt() << ". Reducing damage received." << std::endl;
		int dmgReceived = dmg - this.getDefenseAmnt();
		if (dmgReceived < 0)
			dmgReceived = 0;
		this->CharacterTpl<T>::takeDamage(dmgReceived);
	}
}