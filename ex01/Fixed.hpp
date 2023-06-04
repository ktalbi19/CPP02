#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionnalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &f);
    Fixed &operator=(const Fixed &f2);
    Fixed(const int integer);
    Fixed(const float floating);
    ~Fixed();

    int		getRawBits(void) const;
	void	setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream    &operator<<(std::ostream &o, const Fixed &i);


#endif
