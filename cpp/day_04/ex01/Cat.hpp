#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
            Cat();
            Cat(const Cat &to_copy);
            ~Cat();

    protected:
            int abstract_status() const;
            
            Brain   *cat_brain;
};

#endif