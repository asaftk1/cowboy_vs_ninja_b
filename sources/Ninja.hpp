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
        Character *NinjaTarget;

    public:
        std::string print() const override;

        void move(Character *enemy);

        void slash(Character *target);

        int getSpeed() const
        {
            return speed;
        }
        void setSpeed(int speed)
        {
            this->speed = speed;
        }
        void setNinjaTarget(Character *target)
        {
            this->NinjaTarget = target;
        }
        Character *getNinjaTarget()
        {
            return NinjaTarget;
        }
    };
}
#endif