#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        switch (getCommand(av[1]))
        {
            case  DEBUG:
                debug();
            case INFO:
                info();
            case WARNING:
                warning();
            case ERROR:
            {
                error();
                break;
            }
            case INVALID:
                invalid();
        }
    }
    else
    {
        std::cout << "Usage: ./harlFilter <DEBUG> or <INFO> or <WARNING> or <ERROR>" << std::endl;
    }
    return 0;
}