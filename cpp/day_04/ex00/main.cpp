#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal   *iench = new Dog();
    const Animal   *chatte = new Cat();
    Animal          Animal;
    WrongAnimal     w_animal;
    WrongCat        w_cat;

    iench->makeSound();
    chatte->makeSound();
    Animal.makeSound();
    w_animal.makeSound();
    w_cat.makeSound();
    std::cout << "w_animal is a " << w_animal.getType() << std::endl;
    std::cout << "w_cat is a " << w_cat.getType() << std::endl;
    std::cout << "iench is a " << iench->getType() << std::endl;
    std::cout << "chatte is a " << chatte->getType() << std::endl;
    delete (iench);
    delete (chatte);
}
