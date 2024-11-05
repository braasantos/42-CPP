#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <algorithm>

template <typename T>
void esayfind(T arg1, int arg2)
{
    typename T::iterator it = std::find(arg1.begin(), arg1.end(), arg2);
    if (it != arg1.end())
        std::cout << "Found: " << arg2 << " at position " << std::distance(arg1.begin(), it) << std::endl;
    else
        throw(std::logic_error("No occurence of arg2 in arg1"));
}
