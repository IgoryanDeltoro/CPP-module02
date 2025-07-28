#include "Point.hpp"

int main()
{
    Point a;
    std::cout << a.getX() << std::endl;
    std::cout << a.getY() << std::endl;

    Point p(5.10, 7.18);
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;
}