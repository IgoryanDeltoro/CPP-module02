#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {}
Fixed::Fixed(const int &iv) {
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
Fixed::Fixed(const Fixed &f) : _fixedValue(f._fixedValue) {}
Fixed& Fixed::operator=(const Fixed &f) {
    if (this != &f)
        this->_fixedValue = f._fixedValue;
    return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits() const {
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

bool Fixed::operator>(const Fixed &f) const {
    return _fixedValue > f._fixedValue;
}
bool Fixed::operator<(const Fixed &f) const {
    return _fixedValue < f._fixedValue;
}
bool Fixed::operator>=(const Fixed &f) const {
    return _fixedValue >= f._fixedValue;
}
bool Fixed::operator<=(const Fixed &f) const {
    return _fixedValue <= f._fixedValue;
}
bool Fixed::operator==(const Fixed &f) const {
    return _fixedValue == f._fixedValue;
}
bool Fixed::operator!=(const Fixed &f) const {
    return _fixedValue != f._fixedValue;
}

Fixed Fixed::operator+(const Fixed &f) const
{
    Fixed res;
    res.setRawBits(_fixedValue + f._fixedValue);
    return res;
}
Fixed Fixed::operator-(const Fixed &f) const
{
    Fixed res;
    res.setRawBits(_fixedValue - f._fixedValue);
    return res;
}
Fixed Fixed::operator*(const Fixed &f) const
{
    Fixed res;
    res.setRawBits((_fixedValue * f._fixedValue) >> _fractionalBits);
    return res;
}
Fixed Fixed::operator/(const Fixed &f) const
{
    Fixed res;
    if (_fixedValue && f._fixedValue)
        res.setRawBits((_fixedValue << _fractionalBits) / f._fixedValue);
    return res;
}
Fixed Fixed::operator++() {
    ++_fixedValue;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    ++(*this);
    return tmp;
}
Fixed Fixed::operator--() {
    --_fixedValue;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    --(*this);
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}