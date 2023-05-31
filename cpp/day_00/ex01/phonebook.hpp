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

#endif
