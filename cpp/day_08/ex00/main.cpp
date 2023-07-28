#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> vec;
    int             *found;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    
    try
    {
        found = easyfind(vec, 5);
        std::cout << *found << " was found" << " at " << found 
                  << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "try again" << std::endl;
    }
    return (0);
}