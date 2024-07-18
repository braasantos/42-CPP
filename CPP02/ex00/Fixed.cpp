#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int fixedPoint) : fixedPoint(fixedPoint)
{

}
Fixed::Fixed(const Fixed& other) : fixedPoint(other.fixedPoint)
{
    std::cout << "Copy constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& otherClass)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &otherClass)
        this->fixedPoint = otherClass.fixedPoint;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function was called\n";
    this->fixedPoint = raw;
}