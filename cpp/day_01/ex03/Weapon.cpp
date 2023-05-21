#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string in_type)
:type(in_type)
{}

const std::string &Weapon::getType()
{
    const std::string  &type_REF = this->type;

    return (type_REF);
}

void    Weapon::setType(std::string input)
{
    this->type = input;
}