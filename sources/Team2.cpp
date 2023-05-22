#include "Team2.hpp" // Include the Team2 header file

namespace ariel
{
    // Constructor implementation
    Team2::Team2(Character *initialMember) : Team(initialMember)
    {
    }

    // Override the print function
    void Team2::print() const
    {
        for (const auto &member : getMembers())
        {

            cout << member->print() << endl;
        }
    }
    int Team2::stillAlive()
    {
        int AliveCount = 0;
        for (const auto &member : getMembers())
        {
            if (member->isAlive())
                AliveCount++;
        }
        return AliveCount;
    }

    // Override the attack function
    void Team2::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
        {
            std::__throw_invalid_argument("send nullptr");
        }
        if (stillAlive() == 0)
        {
            std::__throw_runtime_error("team is dead");
        }
        if (enemyTeam->stillAlive() == 0)
        {
            std::__throw_runtime_error("team is dead");
        }

        /// find new leader if the leader is not alive
        /// go over the Cowboys in the team

        if (!getLeader()->isAlive())
        {
            double minValue = std::numeric_limits<double>::max();
            Character *temp = nullptr;
            for (const auto &member : getMembers())
            {

                if (member != getLeader() && member->isAlive())
                {

                    if (member->distance(getLeader()) < minValue)
                    {

                        minValue = member->distance(getLeader());
                        temp = member;
                    }
                }
            }
            setLeader(temp);
        }
        /// find the closest target
        Character *target = findNewTarget(enemyTeam);
        /// make the attack

        for (const auto &member : getMembers())
        {
            if (enemyTeam->stillAlive() == 0)
            {
                return;
            }
            if (!target->isAlive())
            {
                target = findNewTarget(enemyTeam);
            }
            if (member->isAlive() && target && target->isAlive())
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
                if (cowboy)
                {
                    if (cowboy->hasboolets())
                    {
                        cowboy->shoot(target);
                    }
                    else
                    {
                        cowboy->reload();
                    }
                }
                else
                {
                    Ninja *ninja = dynamic_cast<Ninja *>(member);
                    if (ninja)
                    {
                        if (ninja->distance(target) < 1)
                        {
                            ninja->slash(target);
                        }
                        // Ninjas farther away will move towards the target
                        else
                        {
                            ninja->move(target);
                        }
                    }
                }
            }
        }
    }
    Character *Team2::findNewTarget(Team *enemyTeam)
    {
        Character *target = nullptr;
        double minDistanceToLeader = std::numeric_limits<double>::max();
        for (const auto &enemy : enemyTeam->getMembers())
        {

            if (enemy->isAlive())
            {
                double distanceToLeader = getLeader()->distance(enemy);
                if (distanceToLeader < minDistanceToLeader)
                {
                    minDistanceToLeader = distanceToLeader;
                    target = enemy;
                }
            }
        }
        if (target == nullptr)
        {
            setisDead();
        }
        return target;
    }

    // Define any additional member functions or variables specific to Team2

}
