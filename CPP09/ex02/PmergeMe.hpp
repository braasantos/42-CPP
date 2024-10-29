#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>
#include <list>
#include <limits>
#include <iomanip>
#include <algorithm> 

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe& operator=(PmergeMe const &src);
        ~PmergeMe();
};

int checkDigit(char *str);

template <typename T>
int addNumbers(T &cont, char **str)
{
    for (int i = 1; str[i]; i++)
    {
        if (checkDigit(str[i]))
            return (std::cerr << "[ERROR]: Invalid number" << std::endl, 1);
        int value = std::atoi(str[i]);
        cont.push_back(value);
    }
    return 0;
}

template <typename T>
void binaryInsert(T &cont, int start, int end, int value)
{
    while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (cont[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	cont.insert(cont.begin() + start, value);
}

template <typename T>
void FordJohnson(T &cont)
{
    if (cont.size() < 2)
        return ;
    T sValues;
    T bValues;
    for(size_t i = 0; i < (cont.size() / 2); i++)
    {
        if (cont[2 * i] < cont[2 * i + 1])
        {
            sValues.push_back(cont[2 * i]);
            bValues.push_back(cont[2 * i + 1]);
        }
        else
        {
            sValues.push_back(cont[2 * i + 1]);
            bValues.push_back(cont[2 * i]);
        }
    }
    if (cont.size() % 2 != 0)
        sValues.push_back(cont[cont.size() - 1]);
    FordJohnson(bValues);
    FordJohnson(sValues);
    T result = bValues;
    for (size_t i = 0; i < sValues.size(); ++i)
        binaryInsert(result, 0, result.size(), sValues[i]);
    cont = result;
}