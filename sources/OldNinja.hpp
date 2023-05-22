
#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        private:
        static const int HIT_POINTS = 150;
        static const int SPEED = 8;

    public:
        OldNinja(const std::string &name, const Point &location) : Ninja()
        {
            setName(name);
            setLocation(location);
            setHitPoints(HIT_POINTS);
            setSpeed(SPEED);
        }
    };
}
#endif // OLDNINJA_HPP
