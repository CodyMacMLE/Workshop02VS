#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include <string>
#include "character.h"

namespace seneca {
    class Guild {
        /// <summary>
        /// A collection of characters in the form of an array of pointers
        /// </summary>
        Character** m_members;

        /// <summary>
        /// A string with the name of this team
        /// </summary>
        std::string m_guildName;

        /// <summary>
        /// Number of members in the guild
        /// </summary>
        int m_guildSize;
    public:
        /// <summary>
        ///     default constructor
        /// </summary>
        Guild();
        
        /// <summary>
        ///     creates a guild with the name specified as parameter and no members.
        /// </summary>
        Guild(const char* name);
        
        /// <summary>
        ///     copy constructor
        /// </summary>
        Guild(const Guild& src);
        
        /// <summary>
        ///     copy assignment
        /// </summary>
        Guild& operator=(const Guild& src);
        
        /// <summary>
        ///     move constructor
        /// </summary>
        Guild(Guild&& src);
        
        /// <summary>
        ///     move assignment
        /// </summary>
        Guild& operator=(Guild&& src);
        
        /// <summary>
        ///     destructor
        /// </summary>
        ~Guild();
        
        /// <summary>
        ///     adds the character received as parameter to the guild ONLY IF it's not already in the
        ///     guild. Resize the array if necessary. If not already in the guild, increase the max health of
        ///     the character by 300 points.
        /// </summary>
        void addMember(Character* c);
        
        /// <summary>
        ///     searches the team for a character with the name received as parameter and removes it
        ///     from the team. If found in the guild, decrease the max health of the character by 300
        ///     points
        /// </summary>
        void removeMember(const std::string& c);
        
        /// <summary>
        ///     returns the character at the index specified as parameter, or null if the index is out of
        ///     bounds.
        /// </summary>
        Character* operator[](size_t idx) const;
        
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
        void showMembers() const;
    };
}
#endif /* SENECA_GUILD_H */
