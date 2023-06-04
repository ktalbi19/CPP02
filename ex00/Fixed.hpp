#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _fixedPoint;
    static const int    _fractionalBits;
public:
    Fixed();
    Fixed(const Fixed &f);
    Fixed &operator=(const Fixed &f2);
    ~Fixed();
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};



#endif
