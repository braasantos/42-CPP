#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    int i = 2;
    srand(time(NULL));
    while (i > 0)
    {   
        const int value = rand();
        vec.push_back(value); // Add an element
        vec.push_back(2);
        i--;
    }
    try
    {
        ::esayfind(vec, 2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}