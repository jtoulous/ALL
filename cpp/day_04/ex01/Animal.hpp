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
                virtual int abstract_status() const = 0;
                
                std::string type;
                std::string sound;
};

#endif