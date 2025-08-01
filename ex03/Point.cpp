#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const float &x, const float &y): _x(x), _y(y) {}
Point::Point(const Point &p) : _x(p._x), _y(p._y) {}
Point::~Point() {}

bool Point::bsp(Point const a, Point const b, Point const c, Point const p) {
    Fixed abx = b._x - a._x, aby = b._y - a._y;
    Fixed apx = p._x - a._x, apy = p._y - a._y;
    Fixed acx = c._x - a._x, acy = c._y - a._y;

    Fixed crossAB = abx * apy - aby * apx;

    Fixed bcx = c._x - b._x, bcy = c._y - b._y;
    Fixed bpx = p._x - b._x, bpy = p._y - b._y;
    Fixed bax = a._x - b._x, bay = a._y - b._y;

    Fixed crossBC = bcx * bpy - bcy * bpx;

    Fixed cax = a._x - c._x, cay = a._y - c._y;
    Fixed cpx = p._x - c._x, cpy = p._y - c._y;
    Fixed cbx = b._x - c._x, cby = b._y - c._y;

    Fixed crossCA = cax * cpy - cay * cpx;

    bool hasPositive = crossAB > 0 && crossBC > 0 && crossCA > 0;
    bool hasNegative = crossAB < 0 && crossBC < 0 && crossCA < 0;

    return hasPositive || hasNegative;
}
