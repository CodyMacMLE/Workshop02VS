#include "team.h"

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
    }

    /// <summary>
    ///     destructor
    /// </summary>
    Team::~Team() {

    }

    /// <summary>
    ///     adds the character received as parameter to the team ONLY IF the team doesn't have a
    ///     character with the same name. Resize the array if necessary. Use the Character::clone()
    ///     function to make a copy of the parameter.
    /// </summary>
    void Team::addMember(const Character* c) {

    }

    /// <summary>
    ///     searches the team for a character with the name received as parameter and removes it
    ///     from the team.
    /// </summary>
    void Team::removeMember(const std::string& c) {

    }

    /// <summary>
    ///     returns the character ar the index specified as parameter, or null if the index is out of
    ///     bounds.
    /// </summary>
    Character* Team::operator[](size_t idx) const {

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