
#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location) : Ninja()
        {
            setName(name);
            setLocation(location);
            setHitPoints(150);
            setSpeed(8);
        }
    };
}
#endif // OLDNINJA_HPP
