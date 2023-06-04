#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0){
std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed	&Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(f2.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int integer){
    std::cout << "Int construcor called" << std::endl;
    this->_fixedPointValue = (integer << Fixed::_fractionnalBits);
}

Fixed::Fixed(const float floating){
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = std::roundf(floating * (1 << Fixed::_fractionnalBits));
}

float   Fixed::toFloat(void) const{
    //return (static_cast<float>(this->_fixedPointValue / (1 << _fractionnalBits)));
    //return ((float)this->_fixedPointValue / (float)(1 << Fixed::_fractionnalBits));
    return (static_cast<float>(this->_fixedPointValue) / static_cast<float>(1 << _fractionnalBits));
}

int     Fixed::toInt(void) const{
    return this->_fixedPointValue >> this->_fractionnalBits;
}

std::ostream    &operator<<(std::ostream &o, Fixed const &i){
    o << i.toFloat();
    return o;
}

//new fonction for ex02

bool    Fixed::operator>( const Fixed &i ) const {
    return this->getRawBits() > i.getRawBits();
}

bool    Fixed::operator<( const Fixed &i ) const {
    return this->getRawBits() < i.getRawBits();
}

bool    Fixed::operator>=( const Fixed &i ) const {
    return this->getRawBits() >= i.getRawBits();
}

bool   Fixed::operator<=( const Fixed &i ) const {
    return this->getRawBits() <= i.getRawBits();
}

bool  Fixed::operator==( const Fixed &i ) const {
    return this->getRawBits() == i.getRawBits();
}

bool    Fixed::operator!=( const Fixed &i ) const {
    return this->getRawBits() != i.getRawBits();
}

Fixed   Fixed::operator+( const Fixed &i ) const {
    return Fixed( this->toFloat() + i.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &i ) const {
    return Fixed( this->toFloat() - i.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &i ) const {
    return Fixed( this->toFloat() * i.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &i ) const {
    return Fixed( this->toFloat() / i.toFloat() );
}

Fixed&   Fixed::operator++( void ) {
    ++this->_fixedPointValue;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue--;
    return tmp;
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}
