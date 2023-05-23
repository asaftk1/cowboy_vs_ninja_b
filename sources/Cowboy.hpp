#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"

namespace ariel
{
  class Cowboy : public Character
  {
    static const int MAX_BULLETS = 6;
    static const int HIT_POINTS = 110;
    static const int SHOOT = 10;

    int bullets;

  public:
    Cowboy(const std::string &name, const Point &location) : bullets(MAX_BULLETS)
    {
      setName(name);
      setLocation(location);
      setHitPoints(HIT_POINTS);
    }

    int getbullets() const
    {
      return bullets;
    }

    std::string print() const override
    {
      std::ostringstream oss;

      if (getHitPoints() > 0)
      {
        oss << "name: " << getName() << " HitPoints: " << getHitPoints() << " Location: " << getLocation() << std::endl;
      }
      //if the cowboy is dead
      else
      {
        oss << "C "
            << "name: "
            << "(" << getName() << ")"
            << ", Location: " << getLocation() << std::endl;
      }

      return oss.str();
    }
    void shoot(Character *target);

    bool hasboolets() const
    {
      return bullets > 0;
    }

    void reload();
  };

}
#endif // COWBOY_HPP
