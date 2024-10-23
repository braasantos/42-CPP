#include "RPN.hpp"

int isValid(int c)
{
    if (isdigit(c))
        return 1;
    else if (c == '-' || c == '+' || c == '*' || c == '/')
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "[ERROR] Wrong Usage" << std::endl, 1);
    else
    {
        std::vector<char> vec;
        for (int i = 0; av[1][i]; i++)
        {
            while (av[1][i] && isspace(av[1][i]))
                i++;
            if (av[1][i] && isValid(av[1][i]))
            {
                while (vec.size() != 2)
                    vec.push_back(av[1][i]);
            }
        }
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << std::endl;
    }
    return 0;
}