#include "BitcoinExchange.hpp"


void checkData(std::string data)
{
    if (data.length() != 10)
    {
        std::cout << "[ERROR] Invalid date, please use YYYY-MM-DD" << std::endl;
        return ;
    }
    size_t sign = data.find('-');
    size_t ssign = data.find('-', sign + 1);
    if (sign == std::string::npos || ssign == std::string::npos)
        std::cout << "[ERROR] Invalid date format : " << data << std::endl;
    std::string strYear = data.substr(0, sign);
    int year = std::atoi(strYear.c_str());
    if (year > 2022 || year < 2009)
        std::cout << "[ERROR] Not a valid Year : " << year << std::endl;
    std::string strMonth = data.substr(sign + 1, ssign - sign - 1);
    int month = std::atoi(strMonth.c_str());
    if (month > 12 || month < 1)
        std::cout << "[ERROR] Not a valid Month : " << month << std::endl;
    std::string strDay = data.substr(ssign + 1);
    int day = std::atoi(strDay.c_str());
    if (day > 31 || day < 1)
        std::cout << "[ERROR] Not a valid Day : " << day << std::endl;
}   

double checkValue(std::string value)
{
    long price = std::atof(value.c_str());
    if (price > 1000 || price <= 0)
        std::cout << "[ERROR] Not a valid value : " << price << std::endl;
    return (static_cast<double>(price));
}

void checkArg(char *av, std::map<std::string, double> &mapi)
{
    std::string line;
    std::ifstream file(av);
    if (!file.is_open())
    {
        std::cout << "[ERROR] Error while opening the file" << std::endl;
        exit(1);
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos)
            std::cerr << "[ERROR] Invalid line format : " << line << std::endl;
        else 
        {
            std::string data = line.substr(0, pipe - 1);
            std::string value = line.substr(pipe + 1, line.length() - pipe - 1);
            checkData(data);
            double newValue = checkValue(value);
            if (newValue > 1000 || newValue <= 0)
                continue ;
            for(std::map<std::string, double>::const_iterator it = mapi.begin(); it != mapi.end(); ++it)
            {
                // std::cout << it->first << " -- " << data << std::endl;
                if (it->first == data)
                {
                    double price = newValue * it->second;
                    std::cout << it->first << " | " << it->second << " * " << newValue << " -> " << price << std::endl;
                    break ;
                }
                else
                {
                    if (it->first < data)
                    {
                        std::map<std::string, double>::const_iterator lower = mapi.lower_bound(data);
                        if (lower != mapi.begin())
                        {
                            --lower;
                            double price = newValue * lower->second;
                            std::cout << lower->first << " | " << lower->second << " * " << newValue << " -> " << price << std::endl;
                        }
                    }
                    break ;
                }
            }
        }
    }
    file.close();
}

std::map<std::string, double> openCSV(std::string data)
{
    std::map<std::string, double> mapi;
    std::string line;
    std::ifstream file(data.c_str());
    if (!file.is_open())
    {
        std::cout << "[ERROR] Error while opening the file" << std::endl;
        exit(1);
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
        {
            std::cerr << "[ERROR] Invalid line format : " << line << std::endl;
            break ;
        }
        else
        {
            std::string datas = line.substr(0, comma);
            std::string num = line.substr(comma + 1, line.length());
            double key = std::atof(num.c_str());
            mapi.insert(std::make_pair(datas, key));
        }
    }
    file.close();
    return mapi;
}
int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "[ERROR] Wrong Usage" << std::endl, 1);
    else
    {
        std::map<std::string, double> mapi;
        mapi = openCSV("data.csv");
        checkArg(av[1], mapi);
    }
    return 0;
}
