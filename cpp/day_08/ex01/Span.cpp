#include "Span.hpp" 

/////////////////////BUILDERZ//////////////////////////////////////

Span::Span()
: maxSize(0)
{}

Span::Span(unsigned int in_maxSize)
:maxSize(in_maxSize)
{
    if (in_maxSize > std::numeric_limits<std::vector<int>::size_type>::max())
        throw Xception("too big to be contained in a vector");
}

Span::Span(const Span &ref)
{
    if (this != &ref)
        *this = ref;
}

Span::~Span()
{}

Span &Span::operator=(const Span &ref)
{
    std::vector<int>::const_iterator it;

    if (this != &ref)
    {
        maxSize = ref.maxSize;
        this->vec.clear();

        for(it = ref.vec.begin(); it != ref.vec.end(); it++)
            vec.push_back(*it);
    }
    return (*this);
}

////////////////////////GETTERZ/////////////////////////////////


unsigned int    Span::getSize()
{
    return (vec.size());
}

std::vector<int>::iterator  Span::getBegin()
{
    return (vec.begin());
}

std::vector<int>::iterator  Span::getEnd()
{
    return (vec.end());
}

///////////////////////FUNC/////////////////////////////////////


void    Span::addNumber(int to_add)
{
    if (vec.size() >= maxSize)
        throw Xception("vector's maximum size reached");
    vec.push_back(to_add);
}

long     Span::shortestSpan()
{
    long                shortest = 9223372036854775807;
    int                 prev;  

    if (vec.size() < 2)
        throw Xception("at least two numbers needed to use fonction shortestSpan");

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if (it != vec.begin())
            shortest = labs(*it - prev) < shortest ? labs(*it - prev): shortest;
        prev = *it;
    }
    return (shortest);
}

long     Span::longestSpan()
{
    long                longest = 0;
    int                 prev;  

    if (vec.size() < 2)
        throw Xception("at least two numbers needed to use fonction shortestSpan");

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if (it != vec.begin())
            longest = labs(*it - prev) > longest ? labs(*it - prev): longest;
        prev = *it;
    }
    return (longest);
}



////////////////////////////////////////////
//            Xception                    //
////////////////////////////////////////////


Xception::Xception(String in_msg)
: msg(in_msg)
{}

Xception::~Xception() throw()
{}

void    Xception::what()
{
    std::cout << msg << std::endl;
}