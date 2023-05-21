#include "Weapon.hpp"

HumanB::HumanB(std::string input_name):
name(input_name)
{
    this->weapon = nullptr;
}

HumanB::HumanB(std::string input_name, Weapon input_weapon):
name(input_name),
weapon(&input_weapon)
{}

void    HumanB::attack()
{
    if (this->weapon == nullptr)
        std::cout << this->name << " attacks with his head" << std::endl;
    else
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}