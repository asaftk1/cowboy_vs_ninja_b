
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        // Constructor
        Team2(Character *initialMember);

        // Override the print function
        void print() const;

        // Override the attack function
        void attack(Team *enemyTeam);

        int stillAlive();
        Character *findNewTarget(Team *enemyTeam);
    };
}