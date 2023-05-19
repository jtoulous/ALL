#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>

class Contact
{
    public:
            std::string    first_name;
            std::string    last_name;
            std::string    nickname;
            std::string    tel;
            std::string    dark_s;
};

class Phonebook
{
    private:
            Contact Contact_0;
            Contact Contact_1;
            Contact Contact_2;
            Contact Contact_3;
            Contact Contact_4;
            Contact Contact_5;
            Contact Contact_6;
            Contact Contact_7;
            Contact *latest_entry();
            void    print_da_line(Contact to_print, int idx);
            void    print_da_book();
            void    extract_contact(int wanted);

    public:  
            void    add();
            void    search();
};

void    Phonebook::extract_contact(int wanted)
{
    Contact *to_print;

    if (wanted == 1)
        to_print = &this->Contact_0;
    if (wanted == 2)
        to_print = &this->Contact_1;
    if (wanted == 3)
        to_print = &this->Contact_2;
    if (wanted == 4)
        to_print = &this->Contact_3;
    if (wanted == 5)
        to_print = &this->Contact_4;
    if (wanted == 6)
        to_print = &this->Contact_5;
    if (wanted == 7)
        to_print = &this->Contact_6;
    if (wanted == 8)
        to_print = &this->Contact_7;
    std::cout << to_print->first_name << std::endl;
    std::cout << to_print->last_name << std::endl;
    std::cout << to_print->nickname << std::endl;
    std::cout << to_print->tel << std::endl;
    std::cout << to_print->dark_s << std::endl;
}

void    Phonebook::print_da_line(Contact to_print, int idx)
{
    int z;
    int spaces;

    std::cout << idx << " | " ;
    
    if (to_print.first_name.length() < 10)
    {
        z = -1;
        spaces = 10 - to_print.first_name.length();
        while (++z < spaces)
            std::cout << " ";
        std::cout << to_print.first_name << " | ";
    }
    else
        std::cout << to_print.first_name.substr(0, 9) << ". | ";

    if (to_print.last_name.length() < 10)
    {
        z = -1;
        spaces = 10 - to_print.last_name.length();
        while (++z < spaces)
            std::cout << " ";
        std::cout << to_print.last_name << " | ";
    }
    else
        std::cout << to_print.last_name.substr(0, 9) << ". | ";

    if (to_print.nickname.length() < 10)
    {
        z = -1;
        spaces = 10 - to_print.nickname.length();
        while (++z < spaces)
            std::cout << " ";
        std::cout << to_print.nickname << std::endl;
    }
    else
        std::cout << to_print.nickname.substr(0, 9) << "." << std::endl;
}

void    Phonebook::print_da_book()
{
    std::cout << std::endl;
    print_da_line(this->Contact_0, 1);
    if (!this->Contact_1.first_name.empty())
        print_da_line(this->Contact_1, 2);
    if (!this->Contact_2.first_name.empty())
        print_da_line(this->Contact_2, 3);
    if (!this->Contact_3.first_name.empty())
        print_da_line(this->Contact_3, 4);
    if (!this->Contact_4.first_name.empty())
        print_da_line(this->Contact_4, 5);
    if (!this->Contact_5.first_name.empty())
        print_da_line(this->Contact_5, 6);
    if (!this->Contact_6.first_name.empty())
        print_da_line(this->Contact_6, 7);
    if (!this->Contact_7.first_name.empty())
        print_da_line(this->Contact_7, 8);
    std::cout << std::endl;
}

void    Phonebook::search()
{
    std::string input;
    int         z;

    z = 0;
    if(this->Contact_0.first_name.empty())
    {   
        std::cout << "no contacts" << std::endl;
        return ;
    }
    print_da_book();
    std::cout << "enter the number of the target:" << std::endl;
    std::getline(std::cin, input);
    std::cout << std::endl;
    while (input[z] - '0' == 0)
        z++;
    if (input[z] - '0' < 1 || input[z] - '0' > 8)
    {
        std::cout << " sTop DOiNg dRuGs" << std::endl;
        return ;
    }
    if (input[z + 1] != '\0')
    {
        std::cout << " sTop DOiNg dRuGs" << std::endl;
        return ;
    }
    extract_contact(input[z] - '0');
}

Contact *Phonebook::latest_entry()
{
    static int  latest = -1;

    latest++;
    if (latest == 0)
        return (&this->Contact_0);
    if (latest == 1)
        return (&this->Contact_1);
    if (latest == 2)
        return (&this->Contact_2);
    if (latest == 3)
        return (&this->Contact_3);
    if (latest == 4)
        return (&this->Contact_4);
    if (latest == 5)
        return (&this->Contact_5);
    if (latest == 6)
        return (&this->Contact_6);
    latest = -1;
    return (&this->Contact_7);
}

void    Phonebook::add()
{
    Contact         *new_contact;
    std::string     input;

    new_contact = this->latest_entry();

    std::cout << "\n" << "first name?" << std::endl;
    input.clear();
    while (input.empty())
        std::getline(std::cin, input);
    new_contact->first_name = input;

    std::cout << "\n" << "last name?" << std::endl;
    input.clear();
    while (input.empty())
        std::getline(std::cin, input);
    new_contact->last_name = input;

    std::cout << "\n" <<"nickname?" << std::endl;
    input.clear();
    while (input.empty())
        std::getline(std::cin, input);
    new_contact->nickname = input;
    
    std::cout << "\n" <<"telephone number?" << std::endl;
    input.clear();
    while (input.empty())
        std::getline(std::cin, input);
    new_contact->tel = input;
    
    std::cout << "\n" <<"darkest secret?" << std::endl;
    input.clear();
    while (input.empty())
        std::getline(std::cin, input);
    new_contact->dark_s = input;

    std::cout << "\nADDED TO CONTACT LIST" << std::endl;
}

#endif