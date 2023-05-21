#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class   Zombie
{
    public:
            Zombie(std::string in_name);
            ~Zombie();
            void    announce();

    private:
            std::string name;
};

Zombie  *zombieHorde(int  N, std::string name);

# endif