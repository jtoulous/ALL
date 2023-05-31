#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"
# include "Animal.hpp"

class WrongAnimal : public Animal
{
    public:
            WrongAnimal();
            WrongAnimal(const WrongAnimal &to_copy);
            ~WrongAnimal();
};

class WrongCat : public WrongAnimal
{
    public:
            WrongCat();
};

#endif