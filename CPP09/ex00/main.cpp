#include "BitcoinExchange.hpp"

void checkDate(std::string date)
{
    int i = 0;
    while (date[i])
    {
        if (date[i] && date[i] == '|')
            break;
        else
        {
            std::cout << date[i];
            // for (int j = 0; date[j]; j++)
            // {
            //     if (date[i] == '-')
            //         break;
            //     else
            //     {
            //         std::cout << date[i];
            //     }
            // }
        }
        i++;
    }
    int j = 0;
    while (date[j] != '|')
    {
        j++;
    }
    while (date[j])
    {
        std::cout << date[j];
        j++;
    }
    std::cout << std::endl;
}

void checkArg(char *av)
{
    std::string line;
    std::ifstream file(av);
    if (!file.is_open())
    {
        std::cout << "Error while opening the file" << std::endl;
        return ;
    }
    while (std::getline(file, line))
        checkDate(line);
    file.close();
}
int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Wrong Usage" << std::endl, 1);
    else
    {
        checkArg(av[1]);
    }
    return 0;
}
