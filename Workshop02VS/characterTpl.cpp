#include <iostream>
#include "characterTpl.h"

namespace seneca {
	template <typename T>
	CharacterTpl<T>::CharacterTpl(const std::string name, int healthMax) 
		: Character(name) {
		m_healthMax = healthMax;
		m_health = healthMax;
	}

	template <typename T>
	void CharacterTpl<T>::takeDamage(int dmg) {
		m_health -= dmg;
		if (m_health < 0) {
			m_health = 0;
			std::cout << getName() << " has been defeated!" << std::endl;
		}
		else {
			std::cout << getName() << " took " << dmg << " damage, "
				<< m_health << " health remaining." << std::endl;
		}
	}

	template <typename T>
	int CharacterTpl<T>::getHealth() const {
		return static_cast<int>(m_health);
	}

	template <typename T>
	int CharacterTpl<T>::getHealthMax() const {
		return m_healthMax;
	}

	template <typename T>
	void CharacterTpl<T>::setHealth(int health) {
		m_health = health;
	}

	template <typename T>
	void CharacterTpl<T>::setHealthMax(int health) {
		m_healthMax = health;
		m_health = health;
	}
}