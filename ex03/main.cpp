#include "Point.hpp"

int main()
{

    Point abs;

    const Point a(0, 6);
    const Point b(4, 1);
    const Point c(0, 1);
    const Point p(0.7, 5.13);

    if (abs.bsp(a, b, c, p))
        std::cout << "Point is INSIDE the triangle.\n";
    else
        std::cout << "Point is OUTSIDE the triangle.\n";

    return 0;
}
