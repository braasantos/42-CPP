#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <algorithm> 

#define here std::cout << "HERE" << std::endl

class PmergeMe
{
    private:
        std::vector<std::pair<int, int> > vecPair;
        std::vector<int> main;
        std::vector<int> pend;
        std::vector<int> jacobsthalVec;
        std::vector<int> vec;
        int struggler;
    public:
        clock_t before;
        clock_t after;
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe& operator=(PmergeMe const &src);
        ~PmergeMe();
        void FordJohnsonVec(void);
        void formPairsVec(void);
        void checkBiggerVec(void);
        int checkDigit(char *str);
        int addNumbersVec(char **str);
        void sortPairs(std::vector<std::pair<int, int> > &vecPair, int begin, int end);
        void mergePairs(std::vector<std::pair<int, int> > &vecPair, int begin, int mid, int end);
        void createMainPend();
        int binarySearch(std::vector<int > &main, int target, int begin, int end);
        void insertBackMain(void);
        int getJacobsthal(int size);
        void generateJacobsthalNumbers(int max);
        void printBefore();
        void printAfter();
        void printTime();
};

class PmergeMeDeque
{
    private:
        std::deque<std::pair<int, int> > deqPair;
        std::deque<int> main;
        std::deque<int> pend;
        std::deque<int> jacobsthalVec;
        std::deque<int> deq;
        int struggler;
    public:
        clock_t before;
        clock_t after;
        PmergeMeDeque();
        PmergeMeDeque(PmergeMeDeque const &src);
        PmergeMeDeque& operator=(PmergeMeDeque const &src);
        ~PmergeMeDeque();
        void FordJohnsonVec(void);
        void formPairsVec(void);
        void checkBiggerVec(void);
        int checkDigit(char *str);
        int addNumbersVec(char **str);
        void sortPairs(std::deque<std::pair<int, int> > &deqPair, int begin, int end);
        void mergePairs(std::deque<std::pair<int, int> > &deqPair, int begin, int mid, int end);
        void createMainPend();
        int binarySearch(std::deque<int> &main, int target, int begin, int end);
        void insertBackMain(void);
        int getJacobsthal(int size);
        void generateJacobsthalNumbers(int max);
        void printBefore();
        void printAfter();
        void printTime();
};