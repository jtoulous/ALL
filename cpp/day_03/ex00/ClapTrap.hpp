#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
  public:
          ClapTrap(std::string in_name);
          ClapTrap(ClapTrap &to_copy);
          ~ClapTrap();
          void          attack(const std::string &target);
          void          takeDamage(unsigned int amount);
          void          beRepaired(unsigned int amount);
          std::string   &who_is_he();

  private:
          std::string name;
          int         hp;
          int         nrj;
          int         atck;
};

#endif
