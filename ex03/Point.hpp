#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed _x;
        const Fixed _y;
        Point &operator=(const Point &p);

        public:
        Point();
        Point(const float &x, const float &y);
        Point(const Point &p);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;

        
        bool bsp(Point const a, Point const b, Point const c, Point const point);
};

#endif