#include "String_2_guerre.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    String str(argv[1]);
    /*String str2(str);
    String str3(strstr);*/
    
    (void)argc;
    /*std::cout << str << std::endl;
    str =  str - "wesh";
    std::cout << str << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << strstr << std::endl;
    std::cout << strstr + str2 << std::endl;*/
    str -= argv[2];
    std::cout << str << std::endl;
    //str.pop_back();
    //std::cout << str << std::endl;


    return (0);
}