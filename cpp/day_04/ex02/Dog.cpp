#include "Dog.hpp"

Dog::Dog()
: Animal("Dog", "Woof Woof Woof")
{
    dog_brain = new Brain();
    std::cout << "a Dog has been built" 
              << std::endl;
}

Dog::Dog(const Dog &to_copy)
: Animal(to_copy)
{
    dog_brain = new Brain(*to_copy.dog_brain);
    std::cout << "a Dog has been built" 
              << std::endl;
}

Dog::~Dog()
{
    delete (dog_brain);
    std::cout << "a Dog has been destroyed" << std::endl; 
}