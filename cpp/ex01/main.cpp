#include "phonebook.hpp"

int main(void)
{
    Phonebook   the_book;
    std::string input;

    while (1)
    {
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            the_book.add();
        if (input.compare("SEARCH") == 0)
            the_book.search();
    }
    return (0);
}