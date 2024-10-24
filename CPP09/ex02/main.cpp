#include "PmergeMe.hpp"

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

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "[ERROR] wrong usage" << std::endl, 1);
    else
    {
        std::vector<int> vec;
        std::deque<int> deq;
        {
            for (int i = 1; av[i]; i++)
            {
                if (checkDigit(av[i]))
                    return (std::cerr << "[ERROR]" << std::endl, 1);
                int value = std::atoi(av[i]);
                vec.push_back(value);
                deq.push_back(value);
            }
        }
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "[VEC] -> " << vec[i] << std::endl;
        for (size_t i = 0; i < deq.size(); i++)
            std::cout << "[DEQUE] -> " <<deq[i] << std::endl;
    }
}