#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal 
{
    public:
            Animal();
            Animal(std::string type, std::string in_sound);
            Animal(const Animal &to_copy);
            virtual ~Animal();
            
            void                makeSound() const;
            const std::string   &getType() const;

    protected:
                std::string type;
                std::string sound;
};

#endif