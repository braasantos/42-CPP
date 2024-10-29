#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}
PmergeMe& PmergeMe::operator=(PmergeMe const &src)
{
    if (this != &src)
        return *this;
    return *this;
}
PmergeMe::~PmergeMe(){}

int checkDigit(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return 1;
    }
    long num = std::atol(str);
    if (num >= std::numeric_limits<int>::max() || num <= std::numeric_limits<int>::min())
        return 1;
    return 0;
}