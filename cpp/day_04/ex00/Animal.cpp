#include "Animal.hpp"

Animal::Animal()
: type("unknown species"), sound("Draaaaaaaaaaaaa")
{
    std::cout << "an Animal has been built " 
              << std::endl;
}

Animal::Animal(std::string in_type, std::string in_sound)
: type(in_type), sound(in_sound)
{
    std::cout << "an Animal has been built " 
              << std::endl;
}

Animal::Animal(const Animal &to_copy)
: type(to_copy.type), sound(to_copy.sound)
{
    std::cout << "an Animal has been built " 
              << std::endl;
}

Animal::~Animal()
{
    std::cout << "an Animal has been destroyed" 
              << std::endl;
}

void    Animal::makeSound()
{
    std::cout << sound 
              << std::endl;
}