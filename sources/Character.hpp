
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <iostream>
#include <sstream>
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        std::string m_name;
        Point m_location;
        int HitPoints = 0;
        bool isLeader = false;
        bool isPartOfTeam = false;

    protected:
        void setName(const std::string &name)
        {
            m_name = name;
        }
        void setLocation(const Point &location)
        {
            m_location = location;
        }

    public:
        Character() = default;
        virtual ~Character() = default;
        Character(const Character &) = default;                 // Copy constructor
        Character &operator=(const Character &other) = default; // Copy assignment operator
        Character(Character &&other) = default;                 // Move constructor
        Character &operator=(Character &&) = default;

        virtual std::string print() const = 0;

        bool isAlive() const
        {
            return (HitPoints > 0);
        }
        // virtual
        double distance(Character *other)
        {
            return m_location.distance(other->getLocation());
        }
    
        void hit(int descore)
        {
            if (descore < 0)
            {
                std::__throw_invalid_argument("input must be possitiv");
            }
            HitPoints -= descore;
        }

        
        std::string getName() const
        {
            return m_name;
        }
        Point getLocation() const
        {
            return m_location;
        }
        int getHitPoints() const
        {
            return HitPoints;
        }
        void setHitPoints(int hitsP)
        {
            HitPoints = hitsP;
        }
        void setisLeader()
        {
            isLeader = true;
        }
        void setisPartOfGroup()
        {
            isPartOfTeam = true;
        }
        bool getisLeader()const
        {
            return isLeader;
        }
        bool getisPartOfGroup()const
        {
            return isPartOfTeam;
        }
    };
}
#endif // CHARACTER_HPP
