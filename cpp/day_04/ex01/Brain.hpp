#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
            Brain();
            Brain(const Brain &to_copy);
            ~Brain();

    protected:
            std::string *ideas;
};

#endif