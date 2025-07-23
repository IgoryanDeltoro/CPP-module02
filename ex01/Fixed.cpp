#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int &iv) {
    std::cout << "Int constructor called\n";
    if (iv > (INT_MAX >> _fractionalBits) || iv < (INT_MIN >> _fractionalBits))
    {
        std::cout << "Error: the entered number is out of the range to be stored in int\n";
        _fixedValue = 0;
    }
    else
    {
        _fixedValue = iv << _fractionalBits;
    }
}
Fixed::Fixed(const float &fv) {
    std::cout << "Float constructor called\n";
    float floatVal = fv * (1 << _fractionalBits);
    if (floatVal < INT_MIN || floatVal > INT_MAX)
    {
        std::cout << "Error: the entered number is out of the range to be stored in float\n";
        _fixedValue = 0;
    }
    else
    {
        _fixedValue = roundf(floatVal);
    }
}
Fixed::Fixed(const Fixed &f) : _fixedValue(f._fixedValue) {
    std::cout << "Copy constructor called\n";
}
Fixed& Fixed::operator=(const Fixed &f) {
    std::cout << "Assignation operator called\n";
    if (this != &f)
        this->_fixedValue = f._fixedValue;
    return *this;
}
Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return _fixedValue;
};
void Fixed::setRawBits(int const raw) {
    _fixedValue = raw;
};
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedValue) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
    return _fixedValue >> _fractionalBits;
}
std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}