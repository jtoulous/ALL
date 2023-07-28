#pragma once

#include <iterator>
#include <deque>
#include <cstdlib>
#include <stack>

// #include "MutantStack.tpp"

#define IT_TYPE std::random_access_iterator_tag

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
    public:
            MutantStack<T, container>()
            {}

            MutantStack<T, container>(const MutantStack &ref)
            {
                *this = ref;
            }

            ~MutantStack<T, container>()
            {}

            MutantStack &operator=(const MutantStack &ref)
            {
                if (this != &ref)
                {
                    this->stack = ref.stack;
                }
                return (*this);
            }

            class iterator: public std::iterator<IT_TYPE, T>
            {
                public:
                        iterator()
                        : std::iterator<IT_TYPE, T>()
                        {}
            };

            typename MutantStack<T, container>::iterator begin()
            {
                return (stack.begin());
            }       
            
            typename MutantStack<T, container>::iterator end()
            {
                return (stack.end());
            }

            typename MutantStack<T, container>::iterator cbegin()
            {
                return (stack.cbegin());
            }        

            typename MutantStack<T, container>::iterator cend()
            {
                return (stack.cend());
            }

            typename MutantStack<T, container>::iterator rbegin()
            {
                return (stack.rbegin());
            }

            typename MutantStack<T, container>::iterator rend()
            {
                return (stack.rend());
            }

            typename MutantStack<T, container>::iterator crbegin()
            {
                return (stack.crbegin());
            }

            typename MutantStack<T, container>::iterator crend()
            {
                 return (stack.crend());
            }

    private:
            container   stack;
};