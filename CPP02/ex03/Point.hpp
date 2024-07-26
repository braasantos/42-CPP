#pragma once 

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const z;
        Fixed const y;
    public:
        Point();
        Point(float const nbr1, float const nbr2);
        Point(const Fixed& otherClass);
        Point& operator=(const Fixed& other);
        ~Point();
};