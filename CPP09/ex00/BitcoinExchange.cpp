#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "BitcoinExchange created" << std::endl;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    this->mapi = src.mapi;
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
        this->mapi = src.mapi;
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "BitcoinExchange deleted" << std::endl;
}

const char* BitcoinExchange::fileOpening::what() const throw()
{
    return "Error while opening the file";
}


int BitcoinExchange::checkData(std::string data)
{
    if (data.length() != 10)
        return (std::cerr << "[ERROR] Invalid date, please use YYYY-MM-DD" << std::endl, 1);
    size_t sign = data.find('-');
    size_t ssign = data.find('-', sign + 1);
    if (sign == std::string::npos || ssign == std::string::npos)
        return (std::cerr << "[ERROR] Invalid date format : " << data << std::endl, 1 );
    std::string strYear = data.substr(0, sign);
    int year = std::atoi(strYear.c_str());
    if (year < 2009)
        return (std::cerr << "[ERROR] Not a valid Year : " << year << std::endl, 1 );
    std::string strMonth = data.substr(sign + 1, ssign - sign - 1);
    int month = std::atoi(strMonth.c_str());
    if (month > 12 || month < 1)
        return (std::cerr << "[ERROR] Not a valid Month : " << month << std::endl, 1 );
    std::string strDay = data.substr(ssign + 1);
    int day = std::atoi(strDay.c_str());
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap && month == 2)
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return (std::cerr << "[ERROR] Not a valid Day: " << day << std::endl, 1 );
    return 0;
}   

int BitcoinExchange::lastCheck(std::string value)
{
    for (int i = 0; value[i]; i++)
    {
        while (isspace(value[i]))
            i++;
        if (value[i] && (value[i] == '-' || value[i] == '+' || value[i] == '.' ))
        {
            i++;
            continue;
        }
        if (value[i] && !isdigit(value[i]))
        {
            std::cerr << "[ERROR] Not a valid value : " << value << std::endl;
            return 1;
        }
    }
    if (value.length() < 1)
        return (std::cerr << "[ERROR] Value not found" << std::endl, 1);
    return 0;
}

long BitcoinExchange::checkValue(std::string value)
{
    long price = std::atof(value.c_str());
    if (price > 1000)
        std::cerr << "[ERROR] Number too large : " << price << std::endl;
    else if (price < 0)
        std::cerr << "[ERROR] Negative number: " << price << std::endl;
    return (price);
}

std::string cleanValue(std::string value)
{
    int i = 0;
    while(value[i])
    {
        if (isspace(value[i]))
            i++;
        else
            break;
    }
    std::string newValue = value.substr(i);
    return newValue;
}

void BitcoinExchange::checkArg(char *av)
{
    std::string line;
    std::ifstream file(av);
    if (!file.is_open())
        throw BitcoinExchange::fileOpening();
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos)
            std::cerr << "[ERROR] Invalid line format : " << line << std::endl;
        else 
        {
            std::string data = line.substr(0, pipe - 1);
            std::string value = cleanValue(line.substr(pipe + 1));
            if (lastCheck(value) || checkData(data))
                continue ;
            long newValue = checkValue(value);
            if (newValue > 1000 || newValue < 0)
                continue ;
            double otherValue = std::atof(value.c_str());
            std::map<std::string, double>::iterator it = this->mapi.find(data);
            if (it == this->mapi.end())
            {
                it = this->mapi.lower_bound(data);
                it--;
                if (it == this->mapi.begin())
                    exit(1);
            }
            double price = otherValue * it->second;
            std::cout << data << " | " << it->second << " * " << otherValue << " -> " << price << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::openCSV(std::string data)
{
    std::string line;
    std::ifstream file(data.c_str());
    if (!file.is_open())
        throw BitcoinExchange::fileOpening();
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
            if (checkData(datas))
                break ;
            std::string num = line.substr(comma + 1, line.length());
            double key = std::atof(num.c_str());
            this->mapi.insert(std::make_pair(datas, key));
        }
    }
    file.close();
}
