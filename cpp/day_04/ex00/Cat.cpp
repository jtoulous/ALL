#include "Cat.hpp"

Cat::Cat()
: Animal("Cat", "Miaouuuu")
{
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::Cat(const Cat &to_copy)
: Animal(to_copy)
{
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::~Cat()
{
      std::cout << "a Cat has been destroyed" 
                << std::endl;
}