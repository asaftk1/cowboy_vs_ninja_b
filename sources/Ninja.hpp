#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
namespace ariel
{
    class Ninja : public Character
    {
        private:
        static const int HIT = 40;
        int speed;

    public:
        
        std::string print() const override
        {
            std::ostringstream oss;

            if (getHitPoints() > 0)
            {
                oss << "name: " << getName() << " HitPoints: " << getHitPoints() << " Location: " << getLocation() << std::endl;
            }
            else
            {
                oss << "N "
                    << "name: "
                    << "(" << getName() << ")"
                    << ", Location: " << getLocation() << std::endl;
            }

            return oss.str();
        }
        void move(Character *enemy)
        {
            Point enemyLoc = enemy->getLocation();
            Point ninjaLoc = getLocation();
            double distance = ninjaLoc.distance(enemyLoc);

            if (distance > getSpeed())
            {
                Point newLoc = Point::moveTowards(ninjaLoc, enemyLoc, getSpeed());
                setLocation(newLoc);
            }
            else
            {
                // Handle the case when the distance is less than the speed
                // Move directly to the enemy's location or apply another logic based on your requirements
                // For example:
                setLocation(enemyLoc);
            }
            
        }

        void slash(Character *target)
        {
            if (target == this)
            {
                std::__throw_runtime_error("self atack");
            }
            if (isAlive() && getLocation().distance(target->getLocation()) < 1)
            {
                if (!target->isAlive())
                {
                    std::__throw_runtime_error("cant attack dead Character");
                }
                target->hit(HIT);
            }
            else if (!isAlive())
            {

                {
                    std::__throw_runtime_error("dead Character cant attack ");
                }
            }
        }

        int getSpeed()const
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