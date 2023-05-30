#include "Dog.hpp"

Dog::Dog()
: Animal("Dog", "Woof Woof Woof")
{
    std::cout << "a Dog has been built" << std::endl;
}

Dog::Dog(const Dog &to_copy)
: Animal(to_copy)
{
    std::cout << "a Dog has been built" << std::endl;
}

Dog::~Dog()
{
    std::cout << "a Dog has been destroyed" << std::endl; 
}