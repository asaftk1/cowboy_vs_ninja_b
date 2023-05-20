#include "Cowboy.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

void Cowboy::shoot(Character *target)
{
    if(isAlive() && hasboolets()){
        bullets--;
        int currentHitsPoints= target->getHitPoints();
        target->setHitPoints(currentHitsPoints-10);
    }

}

 void Cowboy::reload()
 {
    bullets+=6;
 }