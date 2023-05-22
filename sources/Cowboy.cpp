#include "Cowboy.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

void Cowboy::shoot(Character *target)
{
    if (isAlive() && hasboolets())
    {
        if(target == this)
        {
            std::__throw_runtime_error("self atack");
        }
        if (!target->isAlive())
        {
            std::__throw_runtime_error("cant attack dead Character");
        }
        bullets--;
        target->hit(SHOOT);
    }
    else if (!isAlive())
    {

        {
            std::__throw_runtime_error("dead Character cant attack ");
        }
    }
}

void Cowboy::reload()
{
    if(isAlive()){
    bullets += (6 - bullets);

    }
    else{
        std::__throw_runtime_error("dead cowboy cant realod");
    }
}