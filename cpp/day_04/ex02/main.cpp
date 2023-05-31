#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    int             z = 0;
    Animal          **cats_n_dogs;
    const Animal    *iench = new Dog();
    const Animal    *chatte = new Cat();
    
    /////////   REQUIRED     ///////////////
    cats_n_dogs = new Animal*[10];
    while (z < 5)
    {    
        cats_n_dogs[z] = new Dog();
        z++;
    }
    while (z < 10)
    {    
        cats_n_dogs[z] = new Cat();
        z++;
    }
    z = -1;
    while (++z < 10)
        cats_n_dogs[z]->makeSound();
    z = -1;
    while (++z < 10)
        delete cats_n_dogs[z];
    delete[] cats_n_dogs;
    //////////////////////////////////////////////
    

    iench->makeSound();
    chatte->makeSound();
    std::cout << "iench is a " << iench->getType() << std::endl;
    std::cout << "chatte is a " << chatte->getType() << std::endl;
    delete (iench);
    delete (chatte);

    return (0);
}