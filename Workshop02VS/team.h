//
//  team.h
//  Workshop02
//
//  Created by Cody MacDonald on 2024-10-11.
//
#include <string>
#include "character.h"

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
namespace seneca {
    class Team {
        /// <summary>
        /// An array of pointers to a Character obj that contains all the characters of a team
        /// </summary>
        Character m_team**;
        
        /// <summary>
        /// An array of strings of the name for each character in a team
        /// </summary>
        std::string* m_characterNames;
        
    public:
        /// <summary>
        ///     default constructor
        /// </summary>
        Team();
        
        /// <summary>
        ///     creates a team with the name specified as parameter and no members.
        /// </summary>
        Team(const char* name);
        
        /// <summary>
        ///     copy constructor
        /// </summary>
        Team(const Team& src);
        
        /// <summary>
        ///     copy assignment
        /// </summary>
        Team& operator=(const Team& src);
        
        /// <summary>
        ///     move constructor
        /// </summary>
        Team(Team&& src);
        
        /// <summary>
        ///     move assignment
        /// </summary>
        Team& operator=(Team&& src);
        
        /// <summary>
        ///     destructor
        /// </summary>
        ~Team();
        
        /// <summary>
        ///     adds the character received as parameter to the team ONLY IF the team doesn't have a
        ///     character with the same name. Resize the array if necessary. Use the Character::clone()
        ///     function to make a copy of the parameter.
        /// </summary>
        void addMember(const Character* c);
        
        /// <summary>
        ///     searches the team for a character with the name received as parameter and removes it
        ///     from the team.
        /// </summary>
        void removeMember(const std::string& c);
        
        /// <summary>
        ///     returns the character ar the index specified as parameter, or null if the index is out of
        ///     bounds.
        /// </summary>
        Character* operator[](size_t idx) const;
        
        /// <summary>
        ///     prints to screen the content of current object in the format:
        ///         [Team] TEAM_NAME<endl>
        ///         1: FIRST_CHARACTER<endl>
        ///         2: SECOND_CHARACTER<endl>
        ///         3: THIRD_CHARACTER<endl>
        ///         ...
        ///     Use the operator<< defined for class Character to print a single
        ///     character. If the team is in an empty state, print No team.<endl>
        /// </summary>
        void showMembers() const;
    }
}
#endif /* SENECA_TEAM_H */
