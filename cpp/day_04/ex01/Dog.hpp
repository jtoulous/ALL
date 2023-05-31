#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
            Dog();
            Dog(const Dog &to_copy);
            ~Dog();

    protected:
            int abstract_status() const;

            Brain   *dog_brain;
};

#endif