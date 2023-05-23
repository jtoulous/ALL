#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
    public:
            Fixed();
            Fixed(const Fixed &to_copy);
            Fixed &operator=(const Fixed &to_affect);
            ~Fixed();
            int getRawBits(void) const;
            void setRawBits(int const raw);


    private:
            static int  bits;
            int         fixed_nb;

};

#endif