#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const float &x, const float &y): _x(x), _y(y) {}
Point::Point(const Point &p) : _x(p._x), _y(p._y) {}
Point::~Point() {}

Fixed Point::getX() const {
    return _x;
}
Fixed Point::getY() const {
    return _y;
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const p) {
    Fixed abx = b._x - a._x, aby = b._y - a._y;
    Fixed apx = p._x - a._x, apy = p._y - a._y;
    Fixed acx = c._x - a._x, acy = c._y - a._y;

    Fixed crossA1 = abx * apy - aby * apx;
    Fixed crossA2 = abx * acy - aby * acx;

    Fixed bcx = c._x - b._x, bcy = c._y - b._y;
    Fixed bpx = p._x - b._x, bpy = p._y - b._y;
    Fixed bax = a._x - b._x, bay = a._y - b._y;

    Fixed crossB1 = bcx * bpy - bcy * bpx;
    Fixed crossB2 = bcx * bay - bcy * bax;

    Fixed cax = a._x - c._x, cay = a._y - c._y;
    Fixed cpx = p._x - c._x, cpy = p._y - c._y;
    Fixed cbx = b._x - c._x, cby = b._y - c._y;

    Fixed crossC1 = cax * cpy - cay * cpx;
    Fixed crossC2 = cax * cby - cay * cbx;

    bool d1 = (crossA1 * crossA2 >= 0);
    bool d2 = (crossB1 * crossB2 >= 0);
    bool d3 = (crossC1 * crossC2 >= 0);

    return d1 && d2 && d3;
};
