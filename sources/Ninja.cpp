#include "Ninja.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

void Ninja::slash(Character *target)
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
// move function is used whenever the target distance from the ninja in more then 1 meter
void Ninja::move(Character *enemy)
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
        setLocation(enemyLoc);
    }
}
// overid the Character print function in order to add N at the begining of the print
std::string Ninja::print() const
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