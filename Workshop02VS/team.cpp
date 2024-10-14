#include <utility>
#include <string>
#include "team.h"
#include "character.h"

namespace seneca {
    Team::Team() {
        m_team = nullptr;
        m_teamName = '\0';
		m_teamSize = 0;
    }

    Team::Team(const char* name) {
		m_team = nullptr;
        if (name != nullptr)
            m_teamName = name;
        else
            m_teamName = '\0';
        m_teamSize = 0;
    }

    Team::Team(const Team& src) {
        m_team = nullptr;
        *this = src;
    }

    Team& Team::operator=(const Team& src) {
		// Self assignment check
        if (this != &src) {
			// Clean memory
            for (auto i = 0; i < m_teamSize; ++i) {
                delete m_team[i];
                m_team[i] = nullptr;
            }  
			// Shallow copy the team name & size
			m_teamName = src.m_teamName;
			m_teamSize = src.m_teamSize;
			// Deep copy the team members
			if (src.m_team != nullptr) {
				m_team = new Character* [m_teamSize];
				for (auto i = 0; i < m_teamSize; i++) {
                    m_team[i] = src.m_team[i]->clone();
				}
			}
        }
        return *this;
    }

    /// <summary>
    ///     move constructor
    /// </summary>
    Team::Team(Team&& src) {
        *this = std::move(src);
    }

    /// <summary>
    ///     move assignment
    /// </summary>
    Team& Team::operator=(Team&& src) {
        // Self assignment check
        if (this != &src) {
            // Clean memory
            for (auto i = 0; i < m_teamSize; ++i) {
                delete m_team[i];
            }   

            delete[] m_team;

            // Shallow copy all members
            m_teamName = src.m_teamName;
            m_teamSize = src.m_teamSize;
            m_team = src.m_team;

            // Remove access to data to old object and reset
            src.m_team = nullptr;
            src.m_teamSize = 0;
            src.m_teamName = "\0";

        }
        return *this;
    }

    /// <summary>
    ///     Destructor
    /// </summary>
    Team::~Team() {
        if (m_team != nullptr) {
            for (auto i = 0; i < m_teamSize; ++i) {
				delete m_team[i];
            }
            delete [] m_team;
        }
    }

    /// <summary>
    ///     adds the character received as parameter to the team ONLY IF the team doesn't have a
    ///     character with the same name. Resize the array if necessary. Use the Character::clone()
    ///     function to make a copy of the parameter.
    /// </summary>
    void Team::addMember(const Character* c) {
        int characterExists = 0;
        // Looping to check if character exists and setting flag
        for (auto i = 0; i < m_teamSize; ++i) {
            if (!c->getName().compare(m_team[i]->getName()))
                characterExists = 1;
        }
        // If character does not exist in team -> add member
        if (!characterExists) {
            // Move current team to new array
            Character** newTeam = new Character * [m_teamSize + 1];
            for (auto i = 0; i < m_teamSize; ++i) {
                newTeam[i] = m_team[i];
            }
            // add new member
            newTeam[m_teamSize] = c->clone();
            // delete old pointers
            delete [] m_team;
            // assign newTeam
            m_team = newTeam;
            // increment team size
            ++m_teamSize;
        }    
    }

    /// <summary>
    ///     searches the team for a character with the name received as parameter and removes it
    ///     from the team.
    /// </summary>
    void Team::removeMember(const std::string& c) {
        int characterIndex = -1;
        // Looping to check if character exists and setting flag
        for (auto i = 0; i < m_teamSize; ++i) {
            if (!c.compare(m_team[i]->getName()))
                characterIndex = i;
        }
        // If character does not exist in team -> add member
        if (characterIndex >= 0) {
            
        }
    }

    /// <summary>
    ///     returns the character ar the index specified as parameter, or null if the index is out of
    ///     bounds.
    /// </summary>
    Character* Team::operator[](size_t idx) const {
        return (idx > 0 && idx < m_teamSize) ? m_team[idx] : nullptr;
    }

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
    void Team::showMembers() const {
        if (m_teamSize > 0) {
            std::cout << "[Team] " << m_teamName << std::endl;
            for (auto i = 0; i < m_teamSize; ++i) {
                std::cout << i + 1 << ". " << *m_team[i] << std::endl;
            }
        }
        else {
            std::cout << "No team." << std::endl;
        }
    }
}
