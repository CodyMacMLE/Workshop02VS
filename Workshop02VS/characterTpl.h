//
//  characterTpl.h
//  Workshop02
//
//  Created by Cody MacDonald on 2024-10-10.
//
#include <string>
#include "character.h"

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

namespace seneca {
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
        CharacterTpl(const std::string name, int healthMax);
        
        /// <summary>
        ///     Reduces the current health by the value of the parameter.
        /// </summary>
        void takeDamage(int dmg) override;
        
        /// <summary>
        ///     Returns current health.
        ///     In this design, it is assumed that T supports conversion to int using static_cast.
        /// </summary>
        int getHealth() const override;
        
        /// <summary>
        ///     Returns current maximum health.
        /// </summary>
        int getHealthMax() const override;
        
        /// <summary>
        ///     Sets the current health to the value received as parameter.
        ///     In this design, it is assumed that T has assignment to int operator overloaded.
        /// </summary>
        void setHealth(int health) override;
        
        /// <summary>
        ///     Sets the maximum health and current health to the value of the parameter.
        /// </summary>
        void setHealthMax(int health) override
    }
}

#endif /* SENECA_CHARACTERTPL_H */
