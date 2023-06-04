#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f){
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(f.getRawBits());
}

Fixed&  Fixed::operator=(const Fixed &f2){
    std::cout << "Copy assignement operator called" << std::endl;
    this->setRawBits(f2.getRawBits());
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}

void    Fixed::setRawBits(int const raw){
    this->_fixedPoint = raw;
}
