#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Numbers size() "<< numbers.size() << std::endl;
    int j = 0;
    for(int i = 0; i < MAX_VAL; i++)
        j++;
    std::cout << "Mirror size()" << j << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Tmp size()" << test.size() << std::endl;
        std::cout << "Test size()" <<test.size() << std::endl;
        std::cout << "Test[18] -" <<test[18] << std::endl;
        std::cout << "Test[18] -" <<test[18] << std::endl;
    }
    // try
    // {
    //     std::cout << numbers[780] << std::endl;
    //     std::cout << mirror[780] << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    // int * a = new int();
    // std::cout << a << std::endl;
    return 0;
}      
