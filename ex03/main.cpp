#include "Point.hpp"

int main()
{

    Point abs;

    const Point a(0, 0);
    const Point b(4.5, 1);
    const Point c(2, 3.5);
    const Point p(4.5, 1);

    if (abs.bsp(a, b, c, p))
        std::cout << "Point is INSIDE the triangle.\n";
    else
        std::cout << "Point is OUTSIDE the triangle.\n";

    return 0;
}