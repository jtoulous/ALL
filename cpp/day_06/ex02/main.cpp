#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

#include "Base.hpp"

Base    *generate()
{
    static unsigned int    seed = 0;
    int             random;

    if (seed == 0)
    {
        seed = static_cast<unsigned int>(time(0));
        srand(seed);
    }
    random = rand() % 3;
    std::cout << random << std::endl;
    if (random == 0)
        return (new A);
    else if (random == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base *p)
{
    if (p == NULL)
        return ;
    if (dynamic_cast<A *>(p))
        std::cout << "pointer is class A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "pointer is class B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "pointer is class C" << std::endl;
}

 void    identify(Base &p)
 {
     if (dynamic_cast<A *>(&p))
         std::cout << "ref is class A" << std::endl;
     if (dynamic_cast<B *>(&p))
         std::cout << "ref is class B" << std::endl;
     if (dynamic_cast<C *>(&p))
         std::cout << "ref is class C" << std::endl;
 }

int main(void)
{
    Base    *ptr;
    //Base     ref;

    for(int z = 0; z < 20; z++)
    {
        ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete (ptr);
        std::cout << "\n============================\n" << std::endl;
    }

    return (0);
}