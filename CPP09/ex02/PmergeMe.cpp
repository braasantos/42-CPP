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

int PmergeMe::checkDigit(char *str)
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

int PmergeMe::addNumbersVec(std::vector<int> &cont, char **str)
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

void PmergeMe::formPairsVec(std::vector<int> &cont)
{
    int size =  (cont.size() / 2);
    int i = 0;
    this->struggler = 0;
    while (size != 0)
    {
        this->vecPair.push_back(std::make_pair(cont.at(i), cont.at(i + 1)));
        i += 2;
        size--;
    }
    if (cont.size() % 2 != 0)
        this->struggler = cont[cont.size() - 1];
}
void PmergeMe::mergePairs(std::vector<std::pair<int, int> > &vecPair, int begin, int mid, int end)
{
    size_t i;
	size_t j;
	size_t mergeIndex;

    std::vector<std::pair<int, int> > leftArray(vecPair.begin() + begin, vecPair.begin() + mid + 1);
	std::vector<std::pair<int, int> > rightArray(vecPair.begin() + mid + 1, vecPair.begin() + end + 1);


    i = 0;
	j = 0;
	mergeIndex = begin;
    while (i < leftArray.size() && j < rightArray.size())
	{
		if (leftArray[i].first <= rightArray[j].first)
		{
			vecPair[mergeIndex] = leftArray[i];
			i++;
		}
		else
		{
			vecPair[mergeIndex] = rightArray[j];
			j++;
		}
		mergeIndex++;
	}
    while (i < leftArray.size())
	{
		vecPair[mergeIndex] = leftArray[i];
		i++;
		mergeIndex++;
	}
    while (j < rightArray.size())
	{
		vecPair[mergeIndex] = rightArray[j];
		j++;
		mergeIndex++;
	}
}

void PmergeMe::createMainPend(void)
{
    for (size_t i = 0; i < this->vecPair.size(); i++)
    {
        this->main.push_back(this->vecPair[i].first);
        this->pend.push_back(this->vecPair[i].second);
    }
    if (!this->pend.empty() && !this->main.empty() && this->main[0] >= this->pend[0])
    {
        this->main.insert(this->main.begin(), this->pend[0]);
        this->pend.erase(this->pend.begin()); 
    }
    std::cout << "Main Vec" << std::endl;
    for (size_t i = 0; i < this->main.size(); i++)
    {
        std::cout << this->main[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Pend Vec" << std::endl;
    for (size_t i = 0; i < this->pend.size(); i++)
    {
        std::cout << this->pend[i] << " ";
    }
     std::cout << std::endl;
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > &vecPair, int begin, int end)
{
    int mid;
    if (begin >= end)
        return;
    mid = begin + (end - begin) / 2;
    this->sortPairs(vecPair, begin, mid);
    this->sortPairs(vecPair, mid + 1, end);
    this->mergePairs(vecPair, begin, mid, end);
}

void PmergeMe::checkBiggerVec(void)
{
    for (size_t i = 0; i < this->vecPair.size(); i++)
    {
        if (this->vecPair[i].first < this->vecPair[i].second)
            std::swap(this->vecPair[i].second, this->vecPair[i].first);
    }
    std::cout << "Organize Vec" << std::endl;
    for (size_t i = 0; i < vecPair.size(); i++)
    {
        std::cout << vecPair[i].first << std::endl;
        std::cout << vecPair[i].second << std::endl;
        std::cout << std::endl;
    }
}

int PmergeMe::binarySearch(std::vector<int > &main, int target, int begin, int end)
{
    int mid;
    while (end >= begin)
    {
        mid = end - (begin - end) / 2;
        if (main.at(mid) == target)
            return mid;
        if (main.at(mid) < target)
            end = mid - 1;
        if (main.at(mid) > target)
            begin = mid + 1;
    }
    if (target > main.at(mid))
		return (mid + 1);
	else
		return (mid);
}

int getJacobsthal(size_t size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return 1;
    return getJacobsthal(size - 1) + 2 * getJacobsthal(size - 2);
}

void PmergeMe::insertBackMain(void)
{
    for (size_t i = 0; i < this->pend.size(); i++)
    {
        size_t n = getJacobsthal(this->pend.size());
            std::cout << n << std::endl;
        if (n < this->main.size())
        {
            int pos = this->binarySearch(this->main, n, 0, this->main.size() - 1);
            this->main.insert(this->main.begin() + pos, n);
        }
        else
            continue;
    }
}

void PmergeMe::FordJohnsonVec(std::vector<int> &cont)
{
    std::cout << "Cont\n";
    for (int i = 0; cont[i]; i++)
        std::cout << cont[i] << " ";
    std::cout << std::endl;
    this->formPairsVec(cont);
    std::cout << "Form Pairs" << std::endl;
    for (size_t i = 0; i < vecPair.size(); i++)
    {
        std::cout << vecPair[i].first << std::endl;
        std::cout << vecPair[i].second << std::endl;
        std::cout << std::endl;
    }
    std::cout << "struggler: ";
    std::cout << this->struggler << std::endl;
    this->checkBiggerVec();
    this->sortPairs(this->vecPair, 0, this->vecPair.size() - 1);
        std::cout << "Sort Pairs" << std::endl;
    for (size_t i = 0; i < vecPair.size(); i++)
    {
        std::cout << vecPair[i].first << std::endl;
        std::cout << vecPair[i].second << std::endl;
        std::cout << std::endl;
    }
    this->createMainPend();
    this->insertBackMain();
    std::cout << "Main Vec" << std::endl;
    for (size_t i = 0; i < this->main.size(); i++)
    {
        std::cout << this->main[i] << " ";
    }
    std::cout << std::endl;
}
