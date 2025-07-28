#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

class Fixed {
private:
    int              _fixedValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int &iv);
    Fixed(const float &fv);
    Fixed(const Fixed &f);
    Fixed& operator=(const Fixed& f);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif