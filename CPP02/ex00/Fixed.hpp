#pragma once

# include <iostream>
# include <string>

class Fixed
{
    private:
        int _fixedPoint;
        static const int _fractBits = 8;
    public:
        Fixed();
        Fixed(int fixedPoint);
        Fixed(const Fixed& otherClass);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed& operator=(const Fixed& other);
};