#include "WrongAnimal.hpp"

///////////////////////////////////
/////// CLASS : WrongAnimal ///////
///////////////////////////////////


WrongAnimal::WrongAnimal()
: Animal("WrongAnimal", "kikikiiiiiii")
{
    std::cout << "a WrongAnimal has been built" 
              << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
: Animal(to_copy)
{
    std::cout << "a WrongAnimal been built" 
              << std::endl;
}

WrongAnimal::~WrongAnimal()
{
   std::cout << "a WrongAnimal has been destroyed" 
             << std::endl;
}

//////////////////////////////////
////////   CLASS :  WrongCat  ////
/////////////////////////////////


WrongCat::WrongCat()
: WrongAnimal()
{
    type = "WrongCat";
    std::cout << "a WrongCat has been built" 
              << std::endl;
}