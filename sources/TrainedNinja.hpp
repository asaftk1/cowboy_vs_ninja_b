#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"
namespace ariel
{
     class TrainedNinja : public Ninja
    {
        private:
        static const int HIT_POINTS = 120;
        static const int SPEED = 12;

    public:
        TrainedNinja(const std::string &name, const Point &location):Ninja()
        {
             setName(name);
            setLocation(location);
            setHitPoints(HIT_POINTS);
            setSpeed(SPEED);
        }
    };
} 
#endif  // TRAINEDNINJA_HPP
