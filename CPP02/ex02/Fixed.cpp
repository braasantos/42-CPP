#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    this->_fixedPoint = value << _fractBits;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    this->_fixedPoint = roundf(value * (1 << _fractBits));
}
float Fixed::toFloat() const
{
    return static_cast<float>(this->getRawBits()) / (1 << this->_fractBits);
}

int Fixed::toInt() const
{
   return this->_fixedPoint >> _fractBits;
}

Fixed::Fixed(const Fixed& otherClass) : _fixedPoint(otherClass._fixedPoint)
{
    std::cout << "Copy constructor called\n";
}
std::ostream& operator << (std::ostream& out, const Fixed& obj)
{
    float value = obj.toFloat();
    out << value;
    return out;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_fixedPoint = other._fixedPoint;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
}

bool Fixed::operator > (const Fixed& other) const
{
    return this->_fixedPoint > other._fixedPoint;
}
bool Fixed::operator < (const Fixed& other) const
{
    return this->_fixedPoint < other._fixedPoint;
}
bool Fixed::operator == (const Fixed& other) const
{
    return this->_fixedPoint == other._fixedPoint;
}
bool Fixed::operator <= (const Fixed& other) const
{
    return this->_fixedPoint <= other._fixedPoint;
}
bool Fixed::operator >= (const Fixed& other) const
{
    return this->_fixedPoint >= other._fixedPoint;
}
bool Fixed::operator != (const Fixed& other) const
{
    return this->_fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator + (const Fixed& other) const
{
    return this->toFloat() + other.toFloat();
}
Fixed Fixed::operator - (const Fixed& other) const
{
    return this->toFloat() - other.toFloat();
}
Fixed Fixed::operator * (const Fixed& other) const
{
    return this->toFloat() * other.toFloat();
}
Fixed Fixed::operator / (const Fixed& other) const
{
    return this->toFloat() / other.toFloat();
}

Fixed& Fixed::operator++()
{
    ++_fixedPoint;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    _fixedPoint++;
    return tmp;
}
Fixed& Fixed::operator--()
{
    --_fixedPoint;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    _fixedPoint--;
    return tmp;
}

Fixed& Fixed::min(Fixed& fixedPoint1, Fixed& fixedPoint2)
{
    return (fixedPoint1 < fixedPoint2) ? fixedPoint1 : fixedPoint2;
}

const Fixed& Fixed::min(const Fixed& fixedPoint1, const Fixed& fixedPoint2)
{
    return (fixedPoint1 < fixedPoint2) ? fixedPoint1 : fixedPoint2;
}

Fixed& Fixed::max(Fixed& fixedPoint1, Fixed& fixedPoint2)
{
    return (fixedPoint1 > fixedPoint2) ? fixedPoint1 : fixedPoint2;
}

const Fixed& Fixed::max(const Fixed& fixedPoint1, const Fixed& fixedPoint2)
{
     return (fixedPoint1 > fixedPoint2) ? fixedPoint1 : fixedPoint2;
}