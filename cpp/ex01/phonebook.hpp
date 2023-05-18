#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class Contact
{
    private:

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
            Contact Contact_1;
            Contact Contact_2;
            Contact Contact_3;
            Contact Contact_4;
            Contact Contact_5;
            Contact Contact_6;
            Contact Contact_7;
            Contact Contact_8;

    public:  
            Contact latest_entry();
            void    add();
};

Contact Phonebook::latest_entry()
{
    static int  latest = 1;

    if (latest == 7)
    {    
        latest = 0;
        return (this->Contact_8);
    }
    latest++;
    if (latest  - 1 == 0)
        return (this->Contact_1);
    if (latest - 1 == 1)
        return (this->Contact_2);
    if (latest - 1 == 2)
        return (this->Contact_3);
    if (latest - 1 == 3)
        return (this->Contact_4);
    if (latest - 1 == 4)
        return (this->Contact_5);
    if (latest - 1 == 5)
        return (this->Contact_6);
    if (latest - 1 == 6)
        return (this->Contact_7);
}

void    Phonebook::add()
{
    Contact         *new_contact;
    std::string     input;

    new_contact = this->latest_entry();

    std::cout << "first name?" << std::endl;
    std::cin >> input;
    new_contact->first_name = input;

    std::cout << "last name?" << std::endl;
    std::cin >> input;
    new_contact->last_name = input;

    std::cout << "nickname?" << std::endl;
    std::cin >> input;
    new_contact->nickname = input;
    
    std::cout << "telephone number?" << std::endl;
    std::cin >> input;
    new_contact->tel = input;
    
    std::cout << "darkest secret?" << std::endl;
    std::cin >> input;
    new_contact->dark_s = input;
}

#endif