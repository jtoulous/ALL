#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap    jc("Jacky Chan");
    ScavTrap    bo("Barak Obama");
    ScavTrap    as("Anakin Skywalker");
    ScavTrap    mk("Mia kalif");

    jc.attack(bo.who_is_he());
    bo.takeDamage(0);
    as.takeDamage(9);
    as.takeDamage(2);
    as.attack(mk.who_is_he());
    as.beRepaired(5);
    mk.takeDamage(5);
    mk.beRepaired(4);
}