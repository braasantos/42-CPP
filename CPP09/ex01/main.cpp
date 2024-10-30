#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "[ERROR] Wrong Usage" << std::endl, 1);
    else
    {
        RPN rpn;
        std::string str = av[1];
        for (int i = 0; str[i]; i++)
        {
            while (str[i] && isspace(str[i]))
                i++;
            if (str[i] == '\0')
                break;
            if (rpn.pushToStack(str[i]))
                    return 1;
            while (isspace(str[i]))
                i++;
        }
        if (rpn.stck.size() > 1)
            return (std::cout << "[ERROR]" << std::endl, 1);
        rpn.show();
    }
    return 0;
}