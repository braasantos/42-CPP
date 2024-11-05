#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "[ERROR] Wrong Usage" << std::endl, 1);
    else
    {
        std::string str = av[1];
        if (str.length() < 1)
            return (std::cerr << "[ERROR] Empty string" << std::endl, 1);
        RPN rpn;
        for (int i = 0; str[i]; i++)
        {
            while (str[i] && isspace(str[i]))
                i++;
            if (str[i] == '\0')
                continue;
            if (rpn.pushToStack(str[i]))
                return 1;
        }
        if (rpn.stck.size() > 1)
            return (std::cout << "[ERROR]" << std::endl, 1);
        rpn.show();
    }
    return 0;
}