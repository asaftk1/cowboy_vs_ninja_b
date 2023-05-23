#include "SmartTeam.hpp"
#include <numeric>
using namespace ariel;
using namespace std;
/*
    For the SmartTeam attack :
        1)  first we set for every Character in the team a taget to slash - going over the EnemyTeam
            ## find for every Ninja her closest target
            ## find the Character with the smallest amount of HitPoints and set him as a target
               for all the cowboys in the team

        2)
*/
SmartTeam::SmartTeam(Character *initialMember) : Team2(initialMember)
{
}
void SmartTeam::attack(Team *enemyTeam)
{
    if (stillAlive() == 0)
        return;

    if (enemyTeam == nullptr)
    {
        std::__throw_invalid_argument("send nullptr");
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

    /// make the attack

    for (const auto &member : getMembers())
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy)
        {
            if (getCowBoyTarget() == nullptr || !(getCowBoyTarget()->isAlive()))
            {
                findNewTarget(enemyTeam, member);
            }
            if (member->isAlive() && getCowBoyTarget() && getCowBoyTarget()->isAlive())
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(getCowBoyTarget());
                }
                else
                {
                    cowboy->reload();
                }
            }
        }
    }

    for (const auto &member : getMembers())
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }
        Ninja *ninja = dynamic_cast<Ninja *>(member);
        if (ninja)
        {
            if (ninja->getNinjaTarget() == nullptr || !ninja->getNinjaTarget()->isAlive())
            {
                ninja->setNinjaTarget(findNewTarget(enemyTeam, member));
            }
            // The member is a Ninja

            if (ninja->isAlive() && ninja->getNinjaTarget() && ninja->getNinjaTarget()->isAlive())
            {

                if (ninja->distance(ninja->getNinjaTarget()) < 1.0)
                {
                    ninja->slash(ninja->getNinjaTarget());
                }
                // Ninjas farther away will move towards the target
                else
                {
                    ninja->move(ninja->getNinjaTarget());
                }
            }
        }
    }
}
Character *SmartTeam::findNewTarget(Team *enemyTeam, Character *member)
{
    Character *target = nullptr;
    double minDistanceToLeader = std::numeric_limits<double>::max();
    int minHitPoints = std::numeric_limits<int>::max();

    // For Ninjas, make the closest Character to each Ninja their target
    Ninja *ninja = dynamic_cast<Ninja *>(member);
    if (ninja)
    {
        for (const auto &enemy : enemyTeam->getMembers())
        {
            if (enemy->isAlive())
            {
                double distance = ninja->distance(enemy);
                if (distance < minDistanceToLeader)
                {
                    minDistanceToLeader = distance;
                    target = enemy;
                }
            }
        }
    }
    else
    {
        /// for Cowboys find target - the enemy with the less HitPoints will be all of the cowboys target
        for (const auto &enemy : enemyTeam->getMembers())
        {
            if (enemy->isAlive() && enemy->getHitPoints() < minHitPoints)
            {
                setCowBoyTarget(enemy);
            }
        }
    }

    return target;
}
