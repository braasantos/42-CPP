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


void PmergeMe::printBefore()
{
    std::cout << "[Unsorted vector] -> ";
    for (size_t i = 0; i < this->vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::printAfter()
{
    std::cout << "[Sorted vector] -> ";
    for (size_t i = 0; i < this->vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printTime()
{
    double vec_time = double(this->after - this->before);
    std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector : " << std::fixed
        << vec_time << std::setprecision(5) << " us" << std::endl;
}
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

int PmergeMe::addNumbersVec(char **str)
{
    for (int i = 1; str[i]; i++)
    {
        if (checkDigit(str[i]))
            return (std::cerr << "[ERROR]: Invalid number" << std::endl, 1);
        int value = std::atoi(str[i]);
        this->vec.push_back(value);
    }
    return 0;
}

void PmergeMe::formPairsVec(void)
{
    int size =  (this->vec.size() / 2);
    int i = 0;
    this->struggler = 0;
    while (size != 0)
    {
        this->vecPair.push_back(std::make_pair(this->vec.at(i), this->vec.at(i + 1)));
        i += 2;
        size--;
    }
    if (this->vec.size() % 2 != 0)
        this->struggler = this->vec[this->vec.size() - 1];
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
}

int PmergeMe::binarySearch(std::vector<int > &main, int target, int begin, int end)
{
    int mid;
    while (end >= begin)
    {
        mid = begin + (end - begin) / 2;
        if (main.at(mid) == target)
            return mid;
        if (main.at(mid) < target)
            begin = mid + 1;
        if (main.at(mid) > target)
            end = mid - 1;
    }
    return begin;
}

void PmergeMe::generateJacobsthalNumbers(int max)
{
	int j0 = 1, j1 = 1;

	this->jacobsthalVec.clear();
	this->jacobsthalVec.push_back(j1);
	while (true)
    {
		int j_next = j1 + 2 * j0;
		if (j_next > max) break;
		this->jacobsthalVec.push_back(j_next);                                                                                                                                                   
		j0 = j1; 
		j1 = j_next;
	}
}

void PmergeMe::insertBackMain()
{
    int target;
    int pos;
    this->generateJacobsthalNumbers(this->pend.size());

    // Insert elements in pend based on the Jacobsthal sequence
    for (size_t i = 0; i < this->jacobsthalVec.size(); i++)
    {
        if (this->jacobsthalVec[i] < static_cast<int>(this->pend.size()))
        {
            target = this->pend.at(this->jacobsthalVec[i]);
            pos = this->binarySearch(this->main, target, 0, this->main.size() - 1);
            this->main.insert(this->main.begin() + pos, target);
        }
    }
    // Insert remaining elements not in Jacobsthal sequence
    for (size_t i = 0; i < this->pend.size(); i++)
    {
        if (std::find(this->jacobsthalVec.begin(), this->jacobsthalVec.end(), i) == this->jacobsthalVec.end())
        {
            target = this->pend.at(i);
            pos = this->binarySearch(this->main, target, 0, this->main.size() - 1);
            this->main.insert(this->main.begin() + pos, target);
        }
    }
    if (this->vec.size() % 2 != 0)
	{
		target = this->struggler;
		pos = this->binarySearch(this->main, target, 0, this->pend.size() - 1);
		this->main.insert(this->main.begin() + pos, target);
	}
}

void PmergeMe::FordJohnsonVec(void)
{
    this->formPairsVec();
    this->checkBiggerVec();
    this->sortPairs(this->vecPair, 0, this->vecPair.size() - 1);
    this->createMainPend();
    this->insertBackMain();
    this->vec.clear();
    this->vec.insert(this->vec.begin(), this->main.begin(), this->main.end());

}


PmergeMeDeque::PmergeMeDeque(){}
PmergeMeDeque::PmergeMeDeque(PmergeMeDeque const &src)
{
    *this = src;
}
PmergeMeDeque& PmergeMeDeque::operator=(PmergeMeDeque const &src)
{
    if (this != &src)
        return *this;
    return *this;
}
PmergeMeDeque::~PmergeMeDeque(){}


void PmergeMeDeque::printBefore()
{
    std::cout << "[Unsorted deque] -> ";
    for (size_t i = 0; i < this->deq.size(); i++)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}
void PmergeMeDeque::printAfter()
{
    std::cout << "[Sorted deque] -> ";
    for (size_t i = 0; i < this->deq.size(); i++)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}

void PmergeMeDeque::printTime()
{
    double vec_time = double(this->after - this->before);
    std::cout << "Time to process a range of " << this->deq.size() << " elements with std::vector : " << std::fixed
        << vec_time << std::setprecision(5) << " us" << std::endl;
}
int PmergeMeDeque::checkDigit(char *str)
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

int PmergeMeDeque::addNumbersVec(char **str)
{
    for (int i = 1; str[i]; i++)
    {
        if (checkDigit(str[i]))
            return (std::cerr << "[ERROR]: Invalid number" << std::endl, 1);
        int value = std::atoi(str[i]);
        this->deq.push_back(value);
    }
    return 0;
}

void PmergeMeDeque::formPairsVec(void)
{
    int size =  (this->deq.size() / 2);
    int i = 0;
    this->struggler = 0;
    while (size != 0)
    {
        this->deqPair.push_back(std::make_pair(this->deq.at(i), this->deq.at(i + 1)));
        i += 2;
        size--;
    }
    if (this->deq.size() % 2 != 0)
        this->struggler = this->deq[this->deq.size() - 1];
}
void PmergeMeDeque::mergePairs(std::deque<std::pair<int, int> > &deqPair, int begin, int mid, int end)
{
    size_t i;
	size_t j;
	size_t mergeIndex;

    std::deque<std::pair<int, int> > leftArray(deqPair.begin() + begin, deqPair.begin() + mid + 1);
	std::deque<std::pair<int, int> > rightArray(deqPair.begin() + mid + 1, deqPair.begin() + end + 1);


    i = 0;
	j = 0;
	mergeIndex = begin;
    while (i < leftArray.size() && j < rightArray.size())
	{
		if (leftArray[i].first <= rightArray[j].first)
		{
			deqPair[mergeIndex] = leftArray[i];
			i++;
		}
		else
		{
			deqPair[mergeIndex] = rightArray[j];
			j++;
		}
		mergeIndex++;
	}
    while (i < leftArray.size())
	{
		deqPair[mergeIndex] = leftArray[i];
		i++;
		mergeIndex++;
	}
    while (j < rightArray.size())
	{
		deqPair[mergeIndex] = rightArray[j];
		j++;
		mergeIndex++;
	}
}

void PmergeMeDeque::createMainPend(void)
{
    for (size_t i = 0; i < this->deqPair.size(); i++)
    {
        this->main.push_back(this->deqPair[i].first);
        this->pend.push_back(this->deqPair[i].second);
    }
    if (!this->pend.empty() && !this->main.empty() && this->main[0] >= this->pend[0])
    {
        this->main.insert(this->main.begin(), this->pend[0]);
        this->pend.erase(this->pend.begin()); 
    }
}

void PmergeMeDeque::sortPairs(std::deque<std::pair<int, int> > &deqPair, int begin, int end)
{
    int mid;
    if (begin >= end)
        return;
    mid = begin + (end - begin) / 2;
    this->sortPairs(deqPair, begin, mid);
    this->sortPairs(deqPair, mid + 1, end);
    this->mergePairs(deqPair, begin, mid, end);
}

void PmergeMeDeque::checkBiggerVec(void)
{
    for (size_t i = 0; i < this->deqPair.size(); i++)
    {
        if (this->deqPair[i].first < this->deqPair[i].second)
            std::swap(this->deqPair[i].second, this->deqPair[i].first);
    }
}

int PmergeMeDeque::binarySearch(std::deque<int > &main, int target, int begin, int end)
{
    int mid;
    while (end >= begin)
    {
        mid = begin + (end - begin) / 2;
        if (main.at(mid) == target)
            return mid;
        if (main.at(mid) < target)
            begin = mid + 1;
        if (main.at(mid) > target)
            end = mid - 1;
    }
    return begin;
}

void PmergeMeDeque::generateJacobsthalNumbers(int max)
{
	int j0 = 1, j1 = 1;

	this->jacobsthalVec.clear();
	this->jacobsthalVec.push_back(j1);
	while (true)
    {
		int j_next = j1 + 2 * j0;
		if (j_next > max) break;
		this->jacobsthalVec.push_back(j_next);                                                                                                                                                   
		j0 = j1; 
		j1 = j_next;
	}
}

void PmergeMeDeque::insertBackMain()
{
    int target;
    int pos;
    this->generateJacobsthalNumbers(this->pend.size());

    // Insert elements in pend based on the Jacobsthal sequence
    for (size_t i = 0; i < this->jacobsthalVec.size(); i++)
    {
        if (this->jacobsthalVec[i] < static_cast<int>(this->pend.size()))
        {
            target = this->pend.at(this->jacobsthalVec[i]);
            pos = this->binarySearch(this->main, target, 0, this->main.size() - 1);
            this->main.insert(this->main.begin() + pos, target);
        }
    }
    // Insert remaining elements not in Jacobsthal sequence
    for (size_t i = 0; i < this->pend.size(); i++)
    {
        if (std::find(this->jacobsthalVec.begin(), this->jacobsthalVec.end(), i) == this->jacobsthalVec.end())
        {
            target = this->pend.at(i);
            pos = this->binarySearch(this->main, target, 0, this->main.size() - 1);
            this->main.insert(this->main.begin() + pos, target);
        }
    }
    if (this->deq.size() % 2 != 0)
	{
		target = this->struggler;
		pos = this->binarySearch(this->main, target, 0, this->pend.size() - 1);
		this->main.insert(this->main.begin() + pos, target);
	}
}

void PmergeMeDeque::FordJohnsonVec(void)
{
    this->formPairsVec();
    this->checkBiggerVec();
    this->sortPairs(this->deqPair, 0, this->deqPair.size() - 1);
    this->createMainPend();
    this->insertBackMain();
    this->deq.clear();
    this->deq.insert(this->deq.begin(), this->main.begin(), this->main.end());

}
