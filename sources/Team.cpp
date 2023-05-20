#include "Team.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

void Team::add(Character *member)
{
    m_members.push_back(member);
}

void Team::attack(Team *enemyTeam)
{

    /// find new leader if the leader is not alive
    if (!(leader->isAlive()))
    {
        double minValue = std::numeric_limits<double>::max();
        Character *temp = nullptr;
        for (const auto &member : m_members)
        {
            if (member != leader && member->isAlive())
            {
                if (member->distance(leader) < minValue)
                {
                    minValue = member->distance(leader);
                    temp = member;
                }
            }
        }
        leader = temp;
    }
    /// find the closest target
    Character *target = nullptr;
    double minDistanceToLeader = std::numeric_limits<double>::max();
     for (const auto& enemy : enemyTeam->m_members)
    {
        if (enemy->isAlive())
        {
            double distanceToLeader = leader->distance(enemy);
            if (distanceToLeader < minDistanceToLeader)
            {
                minDistanceToLeader = distanceToLeader;
                target = enemy;
            }
        }
    }
    /// make the attack

    for(const auto& member : m_members)
    {
        if(member->isAlive())
        {
             Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
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
                // The member is a Ninja
                Ninja* ninja = dynamic_cast<Ninja*>(member);
                if(ninja){
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

void Team::print() const
{
    for (const auto &member : m_members)
    {
        cout << member->print() << endl;
    }
}

int Team::stillAlive()
{
    int AliveCount=0;
    for (const auto &member : m_members)
    {
        if(member->isAlive())AliveCount++;
    }
    return AliveCount;
}
