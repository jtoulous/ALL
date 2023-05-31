#include "phonebook.hpp"

int main(void)
{
    Phonebook   the_book;
    std::string input;

    while (std::cin.good())
    {
        std::cout << "\nwatcha wanna do?" << std::endl;
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0 || input.compare("add") == 0)
            the_book.add();
        else if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
            the_book.search();
        else if (input.compare("EXIT") == 0 || input.compare("exit") == 0)
        {
            std::cout << "\nbye bye" << std::endl;
            return (0);
        }
        else if (std::cin.good())
            std::cout << "\nADD, SEARCH or EXIT\n" << std::endl;
    }
    return (0);
}