#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "[ERROR] Wrong Usage" << std::endl, 1);
    else
    {
        RPN rpn;
        for (int i = 0; av[1][i]; i++)
        {
            while (av[1][i] && isspace(av[1][i]))
                i++;
            if (rpn.pushToStack(av[1][i]))
                return 1;
        }
        if (rpn.stck.size() > 1)
            return (std::cout << "[ERROR]" << std::endl, 1);
        rpn.show();
    }
    return 0;
}