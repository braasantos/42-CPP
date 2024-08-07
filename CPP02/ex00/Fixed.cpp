#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int fixedPoint) : _fixedPoint(fixedPoint)
{

}
Fixed::Fixed(const Fixed& other) : _fixedPoint(other._fixedPoint)
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
        this->_fixedPoint = otherClass._fixedPoint;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function was called\n";
    this->_fixedPoint = raw;
}