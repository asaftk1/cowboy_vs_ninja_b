#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"

namespace ariel
{
  class Cowboy : public Character
  {
    int bullets;

  public:
  Cowboy() : Character(),bullets(6)
  {
    Point p(0,0);
    setName("name");
      setLocation(p);
      setHitPoints(110);
  }
    Cowboy(const std::string &name, const Point &location) : Character(), bullets(6)
    {
      setName(name);
      setLocation(location);
      setHitPoints(110);
    }
    int getbullets()
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
