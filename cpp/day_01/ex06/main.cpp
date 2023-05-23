#include "Harl.hpp"

static int  evaluate_madness(std::string tolerance)
{
    if (tolerance.empty())
        return (0);
    if (tolerance == "DEBUG")
        return (1);
    if (tolerance == "INFO")
        return (2);
    if (tolerance == "WARNING")
        return (3);
    if (tolerance == "ERROR")
        return (4);
    return (0);
}

int main(int argc, char **argv)
{
    Harl    harl;
    int     mad_lvl;    

    if (argc > 2)
        return (0);

    if (argc == 1)
        mad_lvl = 1;
    else    
        mad_lvl = evaluate_madness(argv[1]);
    
    switch(mad_lvl)
    {
        case 0:
                std::cout << "[ Probably complaining about insignificant problems ]"
                          << std::endl;
                break;
        case 1:
                harl.complain("DEBUG");
                harl.complain("INFO");
                harl.complain("WARNING");
                harl.complain("ERROR");
                break;
        case 2:
                harl.complain("INFO");
                harl.complain("WARNING");
                harl.complain("ERROR");
                break;
        case 3:
                harl.complain("WARNING");
                harl.complain("ERROR");
                break;
        case 4:
                harl.complain("ERROR");
    }
    return (0);
}