#include "replace.hpp"

variables::variables(char *arg_1, char *arg_2, char *arg_3)
                    :file_name(arg_1), s1(arg_2), s2(arg_3){}

void    variables::errorz()
{
    std::string outfile_name;

    if (file_name.empty())
        quick_kill("first argument is empty");
    if (s1.empty())
        quick_kill("second argument is empty");
    if (s2.empty())
        quick_kill("third argument is empty");
    
    infile.open(file_name.c_str());
    if (!infile.is_open())
        quick_kill("problem opening the infile");
    
    outfile_name = file_name + ".replace";
    outfile.open(outfile_name.c_str());
    if (!outfile.is_open())
    {    
        infile.close();
        quick_kill("problem opening outfile");
    }
}

void    variables::extract_file_content()
{
    char    b;

    while (infile.get(b))
        result.push_back(b);
    infile.close();
}

void    variables::convert_content()
{
    int             z;

    z = 0;
    while (result[z])
    {
        if (result[z] == s1[0])
            compare_n_replace(&z);
        else
            z++;
    }
    outfile << result;
}

void    variables::compare_n_replace(int *z)
{
    std::string new_str;
    int         y = 0;
    int         cpy_z = *z;

    while (s1[y])
    {
        if (s1[y] != result[cpy_z])
        {
            *z += 1;
            return;
        }
        y++;
        cpy_z++;
    }
    y = -1;
    while (++y < *z)
        new_str.push_back(result[y]);
    y = -1;
    while (s2[++y])
        new_str.push_back(s2[y]);
    while (result[cpy_z])
    {    
        new_str.push_back(result[cpy_z]);
        cpy_z++;
    }
    result = new_str;
    *z = *z + s2.size();
}