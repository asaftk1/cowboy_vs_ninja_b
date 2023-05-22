
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#ifndef TEAM_HPP
#define TEAM_HPP
namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> m_members;
        Character *leader;
        bool isDead = false;

    protected:
        Character *getLeader() const { return leader; }

    public:
        Team(Character *initialMember)
        {
            if (initialMember->getisLeader())
            {
                std::__throw_runtime_error("Character cant be leader of two diffrent teams");
            }
            leader = initialMember;
            leader->setisLeader();
            add(leader);
        }

        // Copy constructor
        Team(const Team &other) = delete;

        // Copy assignment operator
        Team &operator=(const Team &other) = delete;

        // Move constructor
        Team(Team &&other) noexcept
            : m_members(std::move(other.m_members)), leader(other.leader)
        {
            other.leader = nullptr;

            other.m_members.clear();
        }

        // Move assignment operator
        Team &operator=(Team &&other) noexcept
        {
            if (this != &other)
            {
                m_members = std::move(other.m_members);
                other.m_members.clear();
            }
            return *this;
        }

        virtual ~Team()
        {
            for (Character *member : m_members)
            {
                if (member != nullptr)
                {
                    member = m_members.back();
                    m_members.pop_back();
                    delete member;
                    member = nullptr;
                }
            }
        }
        void setLeader(Character *newLeader) { leader = newLeader; }
        void setMembers(const std::vector<Character *> &newMembers) { m_members = newMembers; }
        const std::vector<Character *> &getMembers() const { return m_members; }

        void add(Character *member);
        Character *findNewTarget(Team *enemyTeam);
        void findNewLeader();

        int stillAlive();

        void print() const;

        void attack(Team *enemyTeam);
        void setisDead()
        {
            isDead = true;
        }
        bool getisDead() const
        {
            return isDead;
        }
    };
}
#endif