//
//  guild.cpp
//  Workshop02
//
//  Created by Cody MacDonald on 2024-10-12.
//

#include <stdio.h>
#include "guild.h"
#include "character.h"

namespace seneca {
    /// <summary>
    ///     default constructor
    /// </summary>
    Guild::Guild() {
        
    }
    
    /// <summary>
    ///     creates a guild with the name specified as parameter and no members.
    /// </summary>
    Guild::Guild(const char* name) {

    }
    
    /// <summary>
    ///     copy constructor
    /// </summary>
    Guild::Guild(const Guild& src) {
        
    }
    
    /// <summary>
    ///     copy assignment
    /// </summary>
    Guild& Guild::operator=(const Guild& src) {
        return *this;
    }
    
    /// <summary>
    ///     move constructor
    /// </summary>
    Guild::Guild(Guild&& src) {
        
    }
    
    /// <summary>
    ///     move assignment
    /// </summary>
    Guild& Guild::operator=(Guild&& src) {
        return *this;
    }
    
    /// <summary>
    ///     destructor
    /// </summary>
    Guild::~Guild() {
        
    }
    
    /// <summary>
    ///     adds the character received as parameter to the guild ONLY IF it's not already in the
    ///     guild. Resize the array if necessary. If not already in the guild, increase the max health of
    ///     the character by 300 points.
    /// </summary>
    void Guild::addMember(Character* c) {
        
    }
    
    /// <summary>
    ///     searches the team for a character with the name received as parameter and removes it
    ///     from the team. If found in the guild, decrease the max health of the character by 300
    ///     points
    /// </summary>
    void Guild::removeMember(const std::string& c) {
        
    }
    
    /// <summary>
    ///     returns the character at the index specified as parameter, or null if the index is out of
    ///     bounds.
    /// </summary>
    Character* Guild::operator[](size_t idx) const {
        return nullptr;
    }
    
    /// <summary>
    ///     prints to screen the content of current object in the format:
    ///         [Guild] GUILD_NAME<endl>
    ///         1: FIRST_CHARACTER<endl>
    ///         2: SECOND_CHARACTER<endl>
    ///         3: THIRD_CHARACTER<endl>
    ///         ...
    ///         Use the operator<< defined for class Character to print a
    ///         single character. If the team is in an empty state, print No guild.<endl>.
    /// </summary>
    void Guild::showMembers() const {
        
    }
};
