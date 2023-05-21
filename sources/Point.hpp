#include <iostream>
#include <cmath>

namespace ariel
{

    class Point
    {
    private:
        double m_x;
        double m_y;

    public:
        Point():m_x(0),m_y(0){}
        Point(double x_pt,const double y_pt) : m_x(x_pt), m_y(y_pt) {}

        double getX() const
        {
            return m_x;
        }

        double getY() const
        {
            return m_y;
        }

        double distance(const Point &other) const
        {
            double dx_ = m_x - other.m_x;
            double dy_ = m_y - other.m_y;
            return std::sqrt(dx_ * dx_ + dy_ * dy_);
        }
        void print() const
        {
            std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
        }
        static Point moveTowards(const Point &source, const Point &target, double distance) 
        {
            if(distance < 0){
                std::__throw_invalid_argument("distance must be possitiv");
            }
            double dx_ = target.m_x - source.m_x;
            double dy_ = target.m_y - source.m_y;

            double length = std::sqrt(dx_ * dx_ + dy_ * dy_);
            double ratio = distance / length;

            double newX = source.m_x + dx_ * ratio;
            double newY = source.m_y + dy_ * ratio;

            return Point(newX, newY);
            
        }
          bool operator==(const Point &other) const
        {
            return m_x == other.m_x && m_y == other.m_y;
        }

        bool operator!=(const Point &other) const
        {
            return !(*this == other);
        }
        friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << "(" << point.m_x << " , " << point.m_y << ")";
        return out;
    }
    };

}
