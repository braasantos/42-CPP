#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}
Point::Point(float const nbr1, float const nbr2) : x(Fixed(nbr1)),  y(Fixed(nbr2))
{
}
Point::Point(const Point& otherClass) : x(otherClass.x), y(otherClass.y)
{
}
Point &Point::operator=(const Point& other)
{
    if (this != &other)
    {
        this->setX(other.getX());
        this->setY(other.getY());
    }
    return *this;
}
Point::~Point()
{
}
bool Point::operator == (const Point& other) const
{
    if (this->getX() == other.getX())
        return true;
    else if (this->getY() == other.getY())
        return true;
    else
        return false;
}

void Point::setX(const Fixed &value)
{
    const_cast<Fixed&>(this->x) = value;
}
void Point::setY(const Fixed &value)
{
    const_cast<Fixed&>(this->y) = value;
}
Fixed Point::getX(void) const
{
    return this->x;
}
Fixed Point::getY(void) const
{
    return this->y;
}