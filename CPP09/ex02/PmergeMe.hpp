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
    private:
        std::vector<std::pair<int, int> > vecPair;
        std::vector<int> main;
        std::vector<int> pend;
        std::vector<int> jacobsthalVec;
        std::vector<int> positions;
        int struggler;
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe& operator=(PmergeMe const &src);
        ~PmergeMe();
        void FordJohnsonVec(std::vector<int> &cont);
        void formPairsVec(std::vector<int> &cont);
        void checkBiggerVec(void);
        int checkDigit(char *str);
        int addNumbersVec(std::vector<int> &cont, char **str);
        void sortPairs(std::vector<std::pair<int, int> > &vecPair, int begin, int end);
        void mergePairs(std::vector<std::pair<int, int> > &vecPair, int begin, int mid, int end);
        void createMainPend();
        int binarySearch(std::vector<int > &main, int target, int begin, int end);
        void insertBackMain(void);
};


// template <typename T>
// void binaryInsert(T &cont, int start, int end, int value)
// {
//     while (start < end)
// 	{
// 		int mid = start + (end - start) / 2;
// 		if (cont[mid] < value)
// 			start = mid + 1;
// 		else
// 			end = mid;
// 	}
// 	cont.insert(cont.begin() + start, value);
// }

