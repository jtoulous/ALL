#include "replace.hpp"

void    quick_kill(std::string err_msg)
{
    std::cout << err_msg << std::endl;
    exit (69);
}

int main(int argc, char **argv)
{
    variables varz(argv[1], argv[2], argv[3]);

    if (argc != 4)
        return(0);
    varz.errorz();
    varz.extract_file_content();
    varz.convert_content();
    return (0);
}