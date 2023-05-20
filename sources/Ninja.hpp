#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
namespace ariel
{
    class Ninja : public Character
    {
        int speed;

    public:
        // std::string getPrefix() const override
        // {
        //     return "N";
        // }
         std::string print() const override
        {
            std::ostringstream oss;

            if (getHitPoints() > 0)
            {
                oss << "name: " << getName() << " HitPoints: " << getHitPoints()<< " Location: " << getLocation() << std::endl;
            }
            else
            {
                oss << "N" << "name: "
                    << "(" << getName() << ")"
                    << ", Location: " << getLocation() << std::endl;
            }

            return oss.str();
        }
        void move(Character *enemy)
        {
            Point enemyLoc = enemy->getLocation();
            Point NinjaLoc = getLocation();

            if (NinjaLoc.distance(enemyLoc) >= getSpeed())
            {
                Point newLoc = Point::moveTowards(NinjaLoc, enemyLoc, getSpeed());
                setLocation(newLoc);
            }
        }

        void slash(Character *target)
        {
            if (isAlive() && getLocation().distance(target->getLocation()) > 1)
            {
                target->setHitPoints(target->getHitPoints() - 40);
            }
        }

        int getSpeed()
        {
            return speed;
        }
        void setSpeed(int speed)
        {
            this->speed = speed;
        }
    };

}
#endif