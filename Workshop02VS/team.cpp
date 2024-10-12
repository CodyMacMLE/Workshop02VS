#include "team.h"
#include "character.h"

namespace seneca {
    /// <summary>
    ///     default constructor
    /// </summary>
    Team::Team() {
        m_team = nullptr;
        m_teamName = '\0';
		m_teamSize = 0;
    }

    /// <summary>
    ///     creates a team with the name specified as parameter and no members.
    /// </summary>
    Team::Team(const char* name) {
		m_team = nullptr;
        if (name != nullptr)
            m_teamName = name;
        else
            m_teamName = '\0';
        m_teamSize = 0;
    }

    /// <summary>
    ///     copy constructor
    /// </summary>
    Team::Team(const Team& src) {
        m_team = nullptr;
        *this = src;
    }

    /// <summary>
    ///     copy assignment
    /// </summary>
    Team& Team::operator=(const Team& src) {
		// Self assignment check
        if (this != &src) {
			// Clean memory
			delete[] m_team;
			m_team = nullptr;
			// Shallow copy the team name & size
			m_teamName = src.m_teamName;
			m_teamSize = src.m_teamSize;
			// Deep copy the team members
			if (src.m_team != nullptr || src.m_teamSize > 0) {
				m_team = new Character * [m_teamSize];
				for (size_t i = 0; i < m_teamSize; i++) {
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
        m_team = nullptr;
        *this = std::move(src);
    }

    /// <summary>
    ///     move assignment
    /// </summary>
    Team& Team::operator=(Team&& src) {
        // Self assignment check
        if (this != &src) {
            // Clean memory
            delete[] m_team;
            m_team = nullptr;
            // Shallow copy all members
            m_teamName = src.m_teamName;
            m_teamSize = src.m_teamSize;
			m_team = src.m_team; // might need to loop through and assign
            // release old obj's pointer
            src.m_team = nullptr;
        }
        return *this;
    }

    /// <summary>
    ///     destructor
    /// </summary>
    Team::~Team() {
        if (m_team != nullptr) {
            for (auto i = 0; i < m_teamSize; ++i) {
				delete[] m_team[i];
            }
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
            if (c->getName() == m_team[i]->getName())
                characterExists = 1;
        }
        if (characterExists) {
            Character* newCharacter = c->clone();
            if (m_teamSize == 0) {
                m_team = new Character*[1];
                m_team[0] = newCharacter;
            } else {
                Character** tmpTeam = new Character * [m_teamSize];
                tmpTeam = m_team; // Is is copying?
                for (auto i = 0; i < m_teamSize; ++i) {
                    delete[] m_team[i]; // is this deleting ?
                }
                Character** m_team = new Character * [m_teamSize + 1];
                m_team = tmpTeam; // Is is copying?
                for (auto i = 0; i < m_teamSize; ++i) {
                    delete[] tmpTeam[i]; // is this deleting ?
                }
                m_teamSize++;
            }
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
            if (c == m_team[i]->getName())
                characterIndex = i;
        }
        if (characterIndex >= 0) {
            // delete the character and reposition
            delete[] m_team[characterIndex];
            for (auto i = characterIndex; i < m_teamSize - 1; ++i) {
                *m_team[i] = *m_team[i + 1]; // is dereferencing needed (if not am I moving the pointer and losing the object?
            }
            //resize array
            Character** tmpTeam= new Character* [m_teamSize - 1];
            tmpTeam = m_team;
            for (auto i = 0; i < m_teamSize; ++i) {
                delete[] m_team[i]; // is this deleting ?
            }
            Character** m_team= new Character* [m_teamSize - 1];
            m_team = tmpTeam;
            for (auto i = 0; i < m_teamSize; ++i) {
                delete[] tmpTeam[i]; // is this deleting ?
            }
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
        
    }
}
