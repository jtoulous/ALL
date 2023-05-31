#include "Cat.hpp"

Cat::Cat()
: Animal("Cat", "Miaouuuu")
{
    cat_brain = new Brain();
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::Cat(const Cat &to_copy)
: Animal(to_copy)
{
    cat_brain = new Brain(*to_copy.cat_brain);
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::~Cat()
{
    delete (cat_brain);
    std::cout << "a Cat has been destroyed" 
              << std::endl;
}