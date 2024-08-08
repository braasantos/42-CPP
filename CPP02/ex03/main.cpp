#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(2,0);
    Point b(4, 4);
    Point c(6, 0);
    Point point(2.5, 1);

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}