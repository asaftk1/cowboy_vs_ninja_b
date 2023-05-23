#include "Team.hpp"
#include <iostream>
#include <numeric>

using namespace ariel;
using namespace std;

void Team::add(Character *member)
{
    if (m_members.size() == 10)
    {
        std::__throw_runtime_error("only 10 characther is each team");
    }
    else if (member->getisPartOfGroup())
    {
        std::__throw_runtime_error("Character cant be in 2 diffrent groups");
    }
    else
    {
        m_members.push_back(member);
        member->setisPartOfGroup();
    }
}

void Team::attack(Team *enemyTeam)
{
    if(stillAlive() == 0 )return;
    if (enemyTeam == nullptr)
    {
        std::__throw_invalid_argument("send nullptr");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        std::__throw_runtime_error("Enemyteam is dead");
    }
    
    /// find new leader if the leader is not alive
    /// go over the Cowboys in the team

    if (!leader->isAlive())
    {
        double minValue = std::numeric_limits<double>::max();
        Character *temp = nullptr;
        for (const auto &member : m_members)
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            if (cowboy)
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
        }
        for (const auto &member : m_members)
        {

            Ninja *ninja = dynamic_cast<Ninja *>(member);
            if (ninja)
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
        }
        leader = temp;
    }
    /// find the closest target
    Character *target = findNewTarget(enemyTeam);

    /// make the attack

    for (const auto &member : m_members)
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }
        if (!target->isAlive())
        {
            target = findNewTarget(enemyTeam);
        }
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy)
        {

            if (member->isAlive() && target && target->isAlive())
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
        }
    }

    for (const auto &member : m_members)
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }
        if (!target->isAlive())
        {
            target = findNewTarget(enemyTeam);
        }
        // The member is a Ninja
        Ninja *ninja = dynamic_cast<Ninja *>(member);
        if (ninja)
        {
            if (member->isAlive() && target && target->isAlive())
            {

                if (ninja->distance(target) < 1.0)
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

Character *Team::findNewTarget(Team *enemyTeam)
{
    Character *target = nullptr;
    double minDistanceToLeader = std::numeric_limits<double>::max();
    for (const auto &enemy : enemyTeam->m_members)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy);
        if (cowboy)
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
    }
    for (const auto &enemy : enemyTeam->m_members)
    {
        Ninja *ninja = dynamic_cast<Ninja *>(enemy);
        if (ninja)
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
    }
    return target;
}

void Team::print() const
{
    for (const auto &member : m_members)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy)
        {
            cout << member->print() << endl;
        }
    }
    for (const auto &member : m_members)
    {
        Ninja *ninja = dynamic_cast<Ninja *>(member);
        if (ninja)
        {
            cout << member->print() << endl;
        }
    }
}

int Team::stillAlive()
{
    int AliveCount = 0;
    for (const auto &member : m_members)
    {
        if (member->isAlive())
            AliveCount++;
    }
    return AliveCount;
}
