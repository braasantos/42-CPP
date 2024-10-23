#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, double> mapi;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange& operator=(BitcoinExchange const &src);
        ~BitcoinExchange();

        void checkData(std::string data);
        long checkValue(std::string value);
        void checkArg(char *av);
        void openCSV(std::string data);
        int lastCheck(std::string);
        class fileOpening : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};