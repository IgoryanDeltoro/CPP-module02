#include "Point.hpp"

int main()
{

    Point abs;

    const Point a(0, 0);
    const Point b(4, 0);
    const Point c(2, 3);
    const Point p(2.1, 1.5);

    abs.bsp(a, b, c, p);
}