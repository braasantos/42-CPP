#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called\n";
    std::cout << this->_fixedPoint << std::endl;
}
Fixed::Fixed(const int value)
{
    std::cout << value << std::endl;
}
Fixed::Fixed(const float value)
{
    std::cout << value << std::endl;
}
// float Fixed::toFloat() const
// {
    
// }
// int Fixed::toInt() const
// {
    
// }

// Fixed::Fixed(int fixedPoint) : _fixedPoint(_fixedPoint)
// {

// }
// Fixed::Fixed(const Fixed& other) : _fixedPoint(other._fixedPoint)
// {
//     std::cout << "Copy constructor called\n";
// }

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

// Fixed& Fixed::operator=(Fixed const&)
// {
//     std::cout << "Copy assignment operator called\n";
//     return *this;
// }

// int Fixed::getRawBits() const
// {
//     std::cout << "getRawBits member function called\n";
//     return this->_fixedPoint;
// }

// void Fixed::setRawBits(int const raw)
// {
//     std::cout << raw << std::endl;
// }