
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{
    class Team2
    {
    private:
        std::vector<Character *> m_members;

    public:
        
        Team2(Character *initialMember) {}

        // Copy constructor
        Team2(const Team2 &other) = delete;

        // Copy assignment operator
        Team2 &operator=(const Team2 &other) = delete;

        // Move constructor
        Team2(Team2 &&other) noexcept
            : m_members(std::move(other.m_members))
        {
            other.m_members.clear();
        }

        // Move assignment operator
        Team2 &operator=(Team2 &&other) noexcept
        {
            if (this != &other)
            {
                m_members = std::move(other.m_members);
                other.m_members.clear();
            }
            return *this;
        }

        ~Team2()
        {
            for (Character *member : m_members)
            {
                member = m_members.back();
                m_members.pop_back();
                delete member;
            }
        }

        void add(Character *member) {
              m_members.push_back(member);
        }

        static int stillAlive() { return 0; }

        void attack(Team2 *enemyTeam) {}

        void print() const {}

        void slash(Character *target) {}
    };
}