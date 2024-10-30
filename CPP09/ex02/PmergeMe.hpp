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
void PmergeMe<T>::recursiveMergeSort(int left, int right)
{
    int mid;

    if (left >= right)
        return ;
    mid = left + (right - left) / 2;
    recursiveMergeSort(left, mid);
    recursiveMergeSort(mid + 1, right);
    mergeSortedSections(left, mid, right);
}


template <typename Container>
void PmergeMe<Container>::mergeSortedSections(int left, int mid, int right)
{
    // Create left and right containers for merging
    Container LMain(this->_main.begin() + left, this->_main.begin() + mid + 1);
    Container RMain(this->_main.begin() + mid + 1, this->_main.begin() + right + 1);
    // Create temporary containers for merging
    Container LPend(this->_temp.begin() + left, this->_temp.begin() + mid + 1);
    Container RPend(this->_temp.begin() + mid + 1, this->_temp.begin() + right + 1);
    // Iterators for merging
    typename Container::iterator itBeginMain = this->_main.begin() + left;
    typename Container::iterator itBeginPend = this->_temp.begin() + left;
    typename Container::iterator itLMain = LMain.begin();
    typename Container::iterator itLPend = LPend.begin();
    typename Container::iterator itRMain = RMain.begin();
    typename Container::iterator itRPend = RPend.begin();

    // Merging the sorted sections
    while (itLMain != LMain.end() && itRMain != RMain.end() && itLPend != LPend.end() && itRPend != RPend.end())
    {
        if (*itLMain <= *itRMain)
        {
            *itBeginMain = *itLMain;
            *itBeginPend = *itLPend;
            ++itLMain;
            ++itLPend;
        }
        else
        {
            *itBeginMain = *itRMain;
            *itBeginPend = *itRPend;
            ++itRMain;
            ++itRPend;
        }
        ++itBeginMain;
        ++itBeginPend;
    }

    // Copy remaining elements from left section
    while (itLMain != LMain.end() && itLPend != LPend.end())
    {
        *itBeginMain = *itLMain;
        *itBeginPend = *itLPend;
        ++itLMain;
        ++itLPend;
        ++itBeginMain;
        ++itBeginPend;
    }

    // Copy remaining elements from right section
    while (itRMain != RMain.end() && itRPend != RPend.end())
    {
        *itBeginMain = *itRMain;
        *itBeginPend = *itRPend;
        ++itRMain;
        ++itRPend;
        ++itBeginMain;
        ++itBeginPend;
    }
}


template <typename Container>
void PmergeMe<Container>::insert()
{
    size_t i;
    size_t jacobIndex;
    size_t distanceIndex;
    size_t numberInsert;
    size_t start;

    if (this->_temp.empty())
        return ;
    this->_main.insert(this->_main.begin(), this->_temp.front());
    i = 0;
    jacobIndex = 1;
    distanceIndex = getJacobsthal(jacobIndex) * 2;
    numberInsert = 1;

    // Inserting Jacobsthal numbers
    while (i + distanceIndex < this->_temp.size())
    {
        start = i;
        i += distanceIndex;
        while (i > start)
        {
            sortedBinaryInsert(0, i + numberInsert - 1, this->_temp[i]);
            numberInsert++;
            i--;
        }
        i += distanceIndex;
        jacobIndex++;
        distanceIndex = getJacobsthal(jacobIndex) * 2;
    }
    start = i;
    i = this->_temp.size() - 1;
    while (i > start)
    {
        sortedBinaryInsert(0, i + numberInsert - 1, this->_temp[i]);
        numberInsert++;
        i--;
    }
}


template <typename Container>
size_t PmergeMe<Container>::getJacobsthal(size_t n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2));
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