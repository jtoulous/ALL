#include "ClapTrap.hpp"

int main()
{
    ClapTrap    jc("Jacky Chan");
    ClapTrap    bo("Barak Obama");
    ClapTrap    as("Anakin Skywalker");
    ClapTrap    mk("Mia kalif");

    jc.attack(bo.who_is_he());
    bo.takeDamage(0);
    as.takeDamage(9);
    as.takeDamage(2);
    as.attack(mk.who_is_he());
    as.beRepaired(5);
    mk.takeDamage(5);
    mk.beRepaired(4);
}