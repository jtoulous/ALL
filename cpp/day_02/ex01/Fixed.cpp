#include "Fixed.hpp"

int Fixed::bits = 8;

Fixed::Fixed()
:fixed_nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    fixed_nb = to_copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &to_affect)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_affect)
        fixed_nb = to_affect.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{   
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixed_nb);
}

void    Fixed::setRawBits(int const raw)
{
    fixed_nb = raw;
}