#include "phonebook.hpp"

int main(void)
{
    Phonebook   the_book;
    std::string input;

    while (1)
    {
        std::cout << "watcha wanna do?" << std::endl;
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            the_book.add();
        else if (input.compare("SEARCH") == 0)
            the_book.search();
        else if (input.compare("EXIT") == 0)
        {
            std::cout << "bye bye" << std::endl;
            return (0);
        }
        else
            std::cout << "ADD, SEARCH or EXIT" << std::endl;
    }
    return (0);
}