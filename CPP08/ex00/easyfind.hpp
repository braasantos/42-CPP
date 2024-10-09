#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <exception>

template <typename T>

void esayfind(T arg1, int arg2)
{
    int found = 0;
    size_t nfound = 0;
    for (size_t i = 0; i < arg1.size(); i++)
    {
        if (arg2 == arg1[i])
        {
            found++;
            break;
        }
        else
            nfound++;
    }
    if (found == 1)
    {
        std::cout << "FOUND\n";
        return ;
    }
    if (nfound == arg1.size())
        throw(std::logic_error("No occurence of arg2 in arg1"));
}