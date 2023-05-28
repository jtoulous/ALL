#include "Cat.hpp"

Cat::Cat()
: Animal("Cat", "Miaouuuu")
{
    std::cout << type << " has been built" 
              << std::endl;
}

Cat::Cat(const Cat &to_copy)
: Animal(to_copy)
{
    std::cout << type << " has been built" 
              << std::endl;
}

Cat::~Cat()
{
      std::cout << type << " has been destroyed" 
                << std::endl;
}