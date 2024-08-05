#pragma once 

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(float const nbr1, float const nbr2);
        Point(const Point& otherClass);
        Point& operator=(const Point& other);
        ~Point();
        void setX(const Fixed &value);
        void setY(const Fixed &value);
        Fixed getX(void) const;
        Fixed getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed area(Point const &a, Point const &b, Point const &c);