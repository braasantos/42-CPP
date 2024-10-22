#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <limits>

class BitoinExchange
{
    private:
    std::map<int, std::string> mapi;
    public:
    BitoinExchange();
    BitoinExchange(BitoinExchange const &src);
    BitoinExchange& operator=(BitoinExchange const &src);
    ~BitoinExchange();

};