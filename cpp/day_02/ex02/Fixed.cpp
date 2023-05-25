#include "Fixed.hpp"

int Fixed::bits = 8;



////////////////////////////////////////////////////////
/////////////CONSTRUCTORS & DESTRUCTORS///////////////// 
////////////////////////////////////////////////////////

Fixed::Fixed()
:fixed_nb(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}

Fixed::Fixed(const int to_conv)
{
    //std::cout << "Int constructor called" << std::endl;
    if (to_conv > 8388607)
        std::cout << "value exceeds maximum_value that can be contained on 24 bits" << std::endl;
    if (to_conv < -8388608)
        std::cout << "value exceeds minimum_value that can be contained on 24 bits" << std::endl;
    fixed_nb = to_conv << bits;
}

Fixed::Fixed(const float to_conv)
{
    //std::cout << "Float constructor called" << std::endl;
    if (to_conv > 8388607)
        std::cout << "value exceeds maximum_value that can be contained on 24 bits" << std::endl;
    if (to_conv < -8388608)
        std::cout << "value exceeds minimum_value that can be contained on 24 bits" << std::endl;
    fixed_nb = roundf(to_conv * power(2, bits));
}

Fixed::~Fixed()
{   
    //std::cout << "Destructor called" << std::endl;
}





/////////////////////////////////////////////////////
///////////////////OPERATORS/////////////////////////
////////////////////////////////////////////////////

Fixed           &Fixed::operator=(const Fixed &to_affect)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_affect)
        fixed_nb = to_affect.fixed_nb;
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Fixed &to_insert)
{
    os << to_insert.toFloat();
    return (os);
}

bool    Fixed::operator<(const Fixed &to_comp) const
{
    return (this->getRawBits() < to_comp.getRawBits());
}

bool    Fixed::operator>(const Fixed &to_comp) const
{
    return (this->getRawBits() > to_comp.getRawBits());
}

bool    Fixed::operator>=(const Fixed &to_comp) const
{
    return (this->getRawBits() >= to_comp.getRawBits());
}

bool    Fixed::operator<=(const Fixed &to_comp) const
{
    return (this->getRawBits() <= to_comp.getRawBits());
}

bool    Fixed::operator==(const Fixed &to_comp) const
{
    return (this->getRawBits() == to_comp.getRawBits());
}

bool    Fixed::operator!=(const Fixed &to_comp) const
{
    return (this->getRawBits() != to_comp.getRawBits());
}

Fixed    Fixed::operator+(const Fixed &to_add)
{
    Fixed   res;

    res.setRawBits(this->getRawBits() + to_add.getRawBits());
    return (res);
}

Fixed   Fixed::operator-(const Fixed &to_sub)
{
    Fixed   res;

    res.setRawBits(this->getRawBits() - to_sub.getRawBits());
    return (res);   
}

Fixed   Fixed::operator*(const Fixed &to_mult)
{
    Fixed   res;

    res.setRawBits(this->getRawBits() * to_mult.getRawBits());
    return (res);
}

Fixed   Fixed::operator/(const Fixed &to_div)
{
    Fixed   res;

    res.setRawBits(this->getRawBits() / to_div.getRawBits());
    return (res);
}

Fixed   Fixed::operator++(int  to_incre)
{
    Fixed   old;

    (void)to_incre;
    old = *this;
    this->fixed_nb++;
    return (old);
}

Fixed   &Fixed::operator++()
{
    this->fixed_nb++;
    return (*this);
}

Fixed   Fixed::operator--(int to_decre)
{
    Fixed   old(*this);

    (void)to_decre;
    this->fixed_nb--;
    return (old);
}

Fixed   &Fixed::operator--()
{
    this->fixed_nb--;
    return (*this);
}

/////////////////////////////////////////////////////
////////////////REST/////////////////////////////////
////////////////////////////////////////////////////

float   Fixed::toFloat() const
{
    float   res;
   
    res = (float)(fixed_nb) / power(2, bits);
    return (res);
}

int     Fixed::toInt() const
{
    int     res;
    
    res = fixed_nb / power(2, bits);
    return (res);
}

int     Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (fixed_nb);
}

void    Fixed::setRawBits(int const raw)
{
    fixed_nb = raw;
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}