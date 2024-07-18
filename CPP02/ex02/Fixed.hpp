#pragma once

# include <iostream>
# include <string>
# include <cmath>

//Essentially, operator overloading allows you to define 
//how operators behave when applied to objects of your class.

class Fixed
{
    private:
        int _fixedPoint;
        static const int _fractBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& otherClass);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator > (const Fixed& other) const;
        bool operator < (const Fixed& other) const;
        bool operator == (const Fixed& other) const;
        bool operator <= (const Fixed& other) const;
        bool operator >= (const Fixed& other) const;
        bool operator != (const Fixed& other) const;

        // Fixed operator + (const Fixed& other) const;
        // Fixed operator - (const Fixed& other) const;
        // Fixed operator * (const Fixed& other) const;
        // Fixed operator / (const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        // static Fixed &min(Fixed &fixedPoint1, Fixed &fixedPoint2);
        // static Fixed &min(const Fixed &fixedPoint1, const Fixed &fixedPoint2);
        // static Fixed &max(Fixed &fixedPoint1, Fixed &fixedPoint2);
        // static Fixed &max(const Fixed &fixedPoint1, const Fixed &fixedPoint2);
};

std::ostream& operator << (std::ostream& out, Fixed const &obj);