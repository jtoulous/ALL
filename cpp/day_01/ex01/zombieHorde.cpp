#include "Zombie.hpp"
#include <stdio.h>

Zombie  *zombieHorde(int  N, std::string name)
{
  Zombie  *horde;
  int     z;

  z = -1;
  horde = new Zombie[N];
  while (++z < N)
    horde[z] = Zombie(name);
  return (horde);
}