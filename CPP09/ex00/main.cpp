#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "[ERROR] Wrong Usage" << std::endl, 1);
    else
    {
        try
        {
            BitcoinExchange exch;
            exch.openCSV("data.csv");
            exch.checkArg(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    return 0;
}
