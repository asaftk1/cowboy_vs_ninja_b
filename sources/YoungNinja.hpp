#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
// #include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location) : Ninja()
        {
            setName(name);
            setLocation(location);
            setHitPoints(100);
            setSpeed(14);
        }
    };
}
#endif // YOUNGNINJA_HPP
