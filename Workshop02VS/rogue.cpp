#include <iostream>
#include "rogue.h"
#include "character.h"
#include "characterTpl.h"
#include "abilities.h"
#include "weapons.h"

namespace seneca {
	template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
        : CharacterTpl<T>(name, healthMax) {
		m_baseDefense = baseDefense;
		m_baseAttack = baseAttack;
		m_firstAbility = FirstAbility_t();
		m_secondAbility = SecondAbility_t();
		m_weapon = seneca::Dagger();
    }

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
		return m_baseAttack + (2 * static_cast<double>(m_weapon));
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
}
