
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
        
        virtual std::string print() const =0;

        // {
        //     std::ostringstream oss;

        //     if (HitPoints > 0)
        //     {
        //         oss << "name: " << m_name << " HitPoints: " << HitPoints << " Location: " << m_location << std::endl;
        //     }
        //     else
        //     {
        //         oss << getPrefix() << "name: "
        //             << "(" << m_name << ")"
        //             << ", Location: " << m_location << std::endl;
        //     }

        //     return oss.str();
        // }

        //virtual
         bool isAlive()
        {
            if (HitPoints > 0)
                return true;
            return false;
        }
       // virtual
        double distance(Character *other)
        {
            return m_location.distance(other->getLocation());
        }
        // virtual 
        void hit(int descore)
        {
            HitPoints -= descore;
        }

        // virtual
         std::string getName()const
        {
            return m_name;
        }
        // virtual 
        Point getLocation() const
        {
            return m_location;
        }
        // virtual
         int getHitPoints() const
        {
            return HitPoints;
        }
        void setHitPoints(int hitsP)
        {
            HitPoints = hitsP;
        }
    };
}
#endif // CHARACTER_HPP
