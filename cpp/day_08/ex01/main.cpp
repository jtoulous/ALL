#include "Span.hpp"
#include <ctime>

static int random_int()
{
    static int  seeded = 0;

    if (seeded == 0)
        srand(time(NULL));
    seeded = 1;
    return (rand());
}

int main(void)
{
    {
        try
        {
            Span    container(10000);
            Span    container2(10);
            long    tmp;

            for (int z = 0; z < 10000; z++)
                container.addNumber(random_int());

            std::cout << "\nthe size of the vector is " << container.getSize() << std::endl;

            tmp = container.longestSpan();
            std::cout << "the longest span is " << tmp 
                      << std::endl;

            tmp = container.shortestSpan();
            std::cout << "the shortest span is " << tmp 
                      << std::endl;

            
            for (int z = 0; z < 10; z++)
                container2.addNumber(random_int());
            container.addSpan< std::vector<int> >(container2.getBegin(), container2.getEnd());
            
            std::cout << "\nthe size of the vector is " << container.getSize() << " after fonction addSpan" << std::endl;

        }
        catch (Xception &e)
        {
            e.what();
        }
    }

    std::cout << "\n====================================\n" << std::endl;

    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
        return 0;
}
