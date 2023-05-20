#include <iostream>

void    to_upper(char *str)
{
    int z = 0;

    if (!str)
        return ;
    while (str[z])
    {
        if (str[z] >= 'a' && str[z] <= 'z')
            str[z] -= 32;
        z++;
    }
}

int main(int argc, char **argv)
{
    int z = 1;

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
        return (0);
    }
    while (argv[z])
    {
        to_upper(argv[z]);
        std::cout << argv[z];
        z++;
    }
    std::cout << std::endl;
    return (0);
}