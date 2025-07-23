#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &f) {
    std::cout << "Copy constructor called\n";
    *this = f;
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
    return this->_fixedValue;
};
void Fixed::setRawBits(int const raw) {
    this->_fixedValue = raw;
};

