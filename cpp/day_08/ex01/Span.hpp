#pragma once

#include <vector>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <limits>
#include "String_2_guerre.hpp"

class Span
{
    public:
            Span();
            Span(unsigned int in_maxSize);
            Span(const Span &ref);
            ~Span();

            Span    &operator=(const Span &ref); 

            unsigned int                getSize();
            std::vector<int>::iterator  getBegin();
            std::vector<int>::iterator  getEnd();

            void    addNumber(int to_add);
            long    shortestSpan();
            long    longestSpan();
            
            template <typename T>
            void    addSpan(typename T::iterator it_begin, typename T::iterator it_end)
            {
                vec.assign(it_begin, it_end);
            }

    private:
            std::vector<int>    vec;
            unsigned int maxSize;
};

class Xception: public std::exception
{
    public:
            Xception(String in_msg);
            ~Xception() throw();
            void    what();
    
    private:
            String msg;
};