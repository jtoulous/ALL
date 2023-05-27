#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string in_name)
: name(in_name), hp(10), mana(10), atck(0)
{}

ClapTrap::ClapTrap(ClapTrap to_cpy)
{
  this->name = to_cpy.name;
  this->hp = to_cpy.hp;
  this->mana = to_cpy.mana;
  this->atck = to_cpy.atck;
}:
