#include "BitcoinExchange.hpp"

void checkDate(std::string date)
{
    size_t comma = date.find(',');

    if (comma == std::string::npos)
    {
        std::cerr << "Invalid line format: " << date << std::endl;
        break;
    }
    else
    {
        std::string data = date.substr(0, comma);
        std::string num = date.substr(comma + 1);
        std::cout << data;
        int key = std::stoi(num);
        mapi[key] = data;
        // mapi.insert(std::make_pair(date[i]));
    }
    for (const auto& pair : mapi)
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // int j = 0;
    // while (date[j] != '|')
    // {
    //     j++;
    // }
    // while (date[j])
    // {
    //     std::cout << date[j];
    //     j++;
    // }
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

void openCSV(std::string data)
{
    std::map<int, std::string> mapi;
    std::string line;
    std::ifstream file(data.c_str());
    if (!file.is_open())
    {
        std::cout << "Error while opening the file" << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
         size_t comma = date.find(',');

        if (comma == std::string::npos)
        {
            std::cerr << "Invalid line format: " << date << std::endl;
            break;
        }
        else
        {
            std::string data = date.substr(0, comma);
            std::string num = date.substr(comma + 1);
            std::cout << data;
            int key = std::stoi(num);
            mapi[key] = data;
            // mapi.insert(std::make_pair(date[i]));
        }
    }
    file.close();
}
int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Wrong Usage" << std::endl, 1);
    else
    {
        openCSV("data.csv");
        (void)av;
        // checkArg(av[1]);
    }
    return 0;
}
