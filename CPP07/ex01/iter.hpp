#pragma once
#include <iostream>

template <typename T>
void show(T arg)
{
    std::cout << arg << std::endl;
}

template <typename T>
void iter(T* add, int size, void (*func)(T&))
{
    for (int i = 0; i < size; i++)
    {
        func(add[i]);
    }
}
