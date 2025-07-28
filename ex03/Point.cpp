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
    Fixed acx = c._x - a._y, acy = c._y - a._y;

    Fixed crossA1 = abx * apy - aby * apx;
    Fixed crossA2 = abx * acy - aby * acx;

    std::cout << "abx: " << abx << std::endl;
    std::cout << "apx: " << apx << std::endl;
    std::cout << "acx: " << acx << std::endl;

    std::cout << "aby: " << aby << std::endl;
    std::cout << "apy: " << apy << std::endl;
    std::cout << "acy: " << acy << std::endl;

    std::cout << "crossA1: " << crossA1 << std::endl;
    std::cout << "crossA2: " << crossA2 << std::endl;

    Fixed bcx = c._x - b._x, bcy = c._y - b._y;
    Fixed bpx = p._x - b._x, bpy = p._y - b._y;
    Fixed bax = a._x - b._y, bay = a._y - b._y;

    Fixed crossA1 = abx * apy - aby * apx;
    Fixed crossA2 = abx * acy - aby * acx;

    std::cout << "abx: " << abx << std::endl;
    std::cout << "apx: " << apx << std::endl;
    std::cout << "acx: " << acx << std::endl;

    std::cout << "aby: " << aby << std::endl;
    std::cout << "apy: " << apy << std::endl;
    std::cout << "acy: " << acy << std::endl;

    std::cout << "crossA1: " << crossA1 << std::endl;
    std::cout << "crossA2: " << crossA2 << std::endl;

    Fixed abx = b._x - a._x, aby = b._y - a._y;
    Fixed apx = p._x - a._x, apy = p._y - a._y;
    Fixed acx = c._x - a._y, acy = c._y - a._y;

    Fixed crossA1 = abx * apy - aby * apx;
    Fixed crossA2 = abx * acy - aby * acx;

    std::cout << "abx: " << abx << std::endl;
    std::cout << "apx: " << apx << std::endl;
    std::cout << "acx: " << acx << std::endl;

    std::cout << "aby: " << aby << std::endl;
    std::cout << "apy: " << apy << std::endl;
    std::cout << "acy: " << acy << std::endl;

    std::cout << "crossA1: " << crossA1 << std::endl;
    std::cout << "crossA2: " << crossA2 << std::endl;
    return true;
};
