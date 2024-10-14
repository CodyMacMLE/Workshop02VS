#include <stdio.h>
#include "guild.h"
#include "character.h"

namespace seneca {
    /// <summary>
    ///     default constructor
    /// </summary>
    Guild::Guild() : m_guildName("\0"), m_members(nullptr), m_guildSize(0) {}
    
    /// <summary>
    ///     creates a guild with the name specified as parameter and no members.
    /// </summary>
    Guild::Guild(const char* name) : m_guildName(name), m_members(nullptr), m_guildSize(0) {}
    
    /// <summary>
    ///     copy constructor
    /// </summary>
    Guild::Guild(const Guild& src) {
        m_members = nullptr;
        *this = src;
    }
    
    /// <summary>
    ///     copy assignment
    /// </summary>
    Guild& Guild::operator=(const Guild& src) {
        // Self assignment check
        if (this != &src) {
            // Clean memory
            for (auto i = 0; i < m_guildSize; ++i) {
                delete m_members[i];
                m_members[i] = nullptr;
            }
            // Shallow copy the team name & size
            m_guildName = src.m_guildName;
            m_guildSize = src.m_guildSize;
            // Deep copy the team members
            if (src.m_members != nullptr) {
                m_members = new Character * [m_guildSize];
                for (auto i = 0; i < m_guildSize; i++) {
                    m_members[i] = src.m_members[i]->clone();
                }
            }
        }
        return *this;
    }
    
    /// <summary>
    ///     move constructor
    /// </summary>
    Guild::Guild(Guild&& src) {
        *this = std::move(src);
    }
    
    /// <summary>
    ///     move assignment
    /// </summary>
    Guild& Guild::operator=(Guild&& src) {
        // Self assignment check
        if (this != &src) {

            delete[] m_members;

            // Shallow copy all members
            m_guildName = src.m_guildName;
            m_guildSize = src.m_guildSize;
            m_members = src.m_members;
           
            // Reset data and remove access to pointers
            src.m_guildName = "\0";
            src.m_guildSize = 0;
            src.m_members = nullptr;

        }
        return *this;
    }
    
    /// <summary>
    ///     destructor
    /// </summary>
    Guild::~Guild() {
        delete[] m_members;
    }
    
    /// <summary>
    ///     adds the character received as parameter to the guild ONLY IF it's not already in the
    ///     guild. Resize the array if necessary. If not already in the guild, increase the max health of
    ///     the character by 300 points.
    /// </summary>
    void Guild::addMember(Character* c) {
        int characterExists = 0;
        // Looping to check if character exists and setting flag
        for (auto i = 0; i < m_guildSize; ++i) {
            if (!c->getName().compare(m_members[i]->getName()))
                characterExists = 1;
        }
        // If character does not exist in team -> add member
        if (!characterExists) {
            // Move current team to new array
            Character** newTeam = new Character * [m_guildSize + 1];
            for (auto i = 0; i < m_guildSize; ++i) {
                newTeam[i] = m_members[i];
            }
            // add new member
            c->setHealthMax(c->getHealthMax() + 300);
            newTeam[m_guildSize] = c;
            // delete old pointers
            delete[] m_members;
            // assign newTeam
            m_members = newTeam;
            // increment team size
            ++m_guildSize;
        }
    }
    
    /// <summary>
    ///     searches the team for a character with the name received as parameter and removes it
    ///     from the team. If found in the guild, decrease the max health of the character by 300
    ///     points
    /// </summary>
    void Guild::removeMember(const std::string& c) {
        int characterIndex = -1;
        // Looping to check if character exists and setting flag
        for (auto i = 0; i < m_guildSize; ++i) {
            if (!c.compare(m_members[i]->getName())) {
                // Putting health back to normal stats
                m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300);
                characterIndex = i;
            }
        }
        // If character exists remove from array
        if (m_guildSize == 1) {
            delete[] m_members;
            m_guildSize--;
        } else if (characterIndex >= 0) {
            for (auto i = characterIndex; i < m_guildSize; i++) {
                m_members[i] = m_members[i + 1];
            }
            Character** newMembers = new Character* [m_guildSize - 1];
            newMembers = m_members;
            m_members = newMembers;
            m_guildSize--;
        }
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
        if (m_guildSize > 0) {
            std::cout << "[Guild] " << m_guildName << std::endl;
            for (auto i = 0; i < m_guildSize; ++i) {
                std::cout << i + 1 << ". " << *m_members[i] << std::endl;
            }
        } else {
            std::cout << "No guild." << std::endl;
        }
    }
};
