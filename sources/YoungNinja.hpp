#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
// #include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    private:
        static const int HIT_POINTS = 100;
        static const int SPEED = 14;

    public:
        YoungNinja(const std::string &name, const Point &location) : Ninja()
        {
            setName(name);
            setLocation(location);
            setHitPoints(HIT_POINTS);
            setSpeed(SPEED);
            setNinjaTarget(nullptr);
        }
    };
}
#endif // YOUNGNINJA_HPP
