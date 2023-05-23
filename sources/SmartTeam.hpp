#include "Team2.hpp"

namespace ariel
{
    class SmartTeam : public Team2
    {
    private:
        Character *CowBoyTarget = nullptr;

    public:
        // Constructor
        SmartTeam(Character *initialMember);

        // Override the attack function
        void attack(Team *enemyTeam);

        // Override the FindNewTarget function

        Character *findNewTarget(Team *enemyTeam, Character *member);

        void setCowBoyTarget(Character *target)
        {
            CowBoyTarget = target;
        }
        Character *getCowBoyTarget()
        {
            return CowBoyTarget;
        }
       
    };
}