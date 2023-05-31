#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "a Brain has been built" 
              << std::endl;
    ideas = new std::string[100];
}

Brain::~Brain()
{
    std::cout << "a Brain has been destroyed" 
              << std::endl;
    delete[] ideas;
}

Brain::Brain(const Brain &to_copy)
{
    int     z = -1;

    while (++z < 100)
        ideas[z] = std::string(to_copy.ideas[z]);
    std::cout << "a Brain has been built" 
              << std::endl;
}