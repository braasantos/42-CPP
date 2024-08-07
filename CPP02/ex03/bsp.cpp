#include "Fixed.hpp"
#include "Point.hpp"

//shoelace formula
// Area=21​∣x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)∣

/// @brief  we are going to convert the the fixed-point into floating-points to ensure precision
///         the area is the total space of the triangle 

/// @param a 
/// @param b 
/// @param c 
/// @return 
Fixed area(Point const &a, Point const &b, Point const &c)
{
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();

    float area = std::abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2.0f;
    return Fixed(area);
}
/// @brief  Functio of the triangle that have 3 vertices A B C
///         and these points are connected to form a triangle and we need to check if a point P is inside
///         the triangle or not 
/// @param a 
/// @param b 
/// @param c 
/// @param point 
/// @return 
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // principal area
    Fixed areaABC = area(a, b, c);

    // sub-areas
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);

     if (areaPAB.getRawBits() == 0 || areaPBC.getRawBits() == 0 || areaPCA.getRawBits() == 0)
        return (false);
    // if the point is inside the triangle that means that the sub-areas will be
    // equal to the principal area and if not the sub-areas will be greater than
    // the principal
    return (areaPAB + areaPBC + areaPCA).getRawBits() == areaABC.getRawBits();
}