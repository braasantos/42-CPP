#include <iostream>
#include <cmath> // For roundf

class Fixed {
public:
    Fixed(float value) {
        _fixedPoint = static_cast<int>(roundf(value * (1 << _fractBits)));
    }

    Fixed(int value) {
        _fixedPoint = value << _fractBits;
    }

    float toFloat() const {
        return static_cast<float>(this->getRawBits()) / (1 << this->_fractBits);
    }

    int getRawBits() const {
        return _fixedPoint;
    }

    static const int _fractBits = 8;
        Fixed operator * (const Fixed& other) const;

private:
    int _fixedPoint;
};
Fixed Fixed::operator * (const Fixed& other) const
{
    int result = this->_fixedPoint * other._fixedPoint;
    int result2 = result >> _fractBits;
    return result2;
}
// Overload the << operator for output
std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    out << obj.toFloat();
    return out;
}

int main() {
    Fixed a(5.05f);
    Fixed b(2);
    Fixed result = a * b; // Assuming operator* is correctly defined
    
    std::cout << "Fixed-point representation of a: " << a.getRawBits() << std::endl;
    std::cout << "Fixed-point representation of b: " << b.getRawBits() << std::endl;
    std::cout << "Fixed-point representation of result: " << result.getRawBits() << std::endl;
    std::cout << "Floating-point value of result: " << result << std::endl;

    return 0;
}
