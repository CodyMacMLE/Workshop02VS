#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"
#include "health.h"

namespace seneca {

    /// Template types:
    ///     - T: The type of the object storing the health.
    template <typename T>
    class CharacterTpl : public Character {
        /// <summary>
        ///     An integer representing the maximum health this character can have
        /// </summary>
        int m_healthMax;
        
        /// <summary>
        ///     An object of type T representing the current health of the character.
        ///     When this value gets to 0, the character died.
        /// </summary>
        T m_health;
        
    public:
        /// <summary>
        ///     A custom constructor that receives the name of the character and the maximum health;
        ///     initializes the current instance with the values of the paameters and set the current health to
        ///     maximum.
        /// </summary>
        CharacterTpl(const char* name, int healthMax);
        
        /// <summary>
        ///     Reduces the current health by the value of the parameter.
        /// </summary>
        virtual void takeDamage(int dmg) override;
        
        /// <summary>
        ///     Returns current health.
        ///     In this design, it is assumed that T supports conversion to int using static_cast.
        /// </summary>
        virtual int getHealth() const override;
        
        /// <summary>
        ///     Returns current maximum health.
        /// </summary>
        virtual int getHealthMax() const override;
        
        /// <summary>
        ///     Sets the current health to the value received as parameter.
        ///     In this design, it is assumed that T has assignment to int operator overloaded.
        /// </summary>
        virtual void setHealth(int health) override;
        
        /// <summary>
        ///     Sets the maximum health and current health to the value of the parameter.
        /// </summary>
        virtual void setHealthMax(int health) override;
    };

    template <typename T>
    CharacterTpl<T>::CharacterTpl(const char* name, int healthMax)
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

#endif /* SENECA_CHARACTERTPL_H */
