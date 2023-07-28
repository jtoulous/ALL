#pragma once

#include <exception>

template <typename T>
int   *easyfind(T container, int nb)
{
    typename T::iterator it;

    for (it = container.begin(); it != container.end(); it++)
    {
        if (*it == nb)
            return (&(*it));
    }
    throw std::exception();
}