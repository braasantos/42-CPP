#pragma once
#include <iostream>
#include <string.h>

template <typename T>
class Array
{
    private:
        T n;
    public:
        Array();
        Array( T n );
        // Array(unsigned int n );
        Array( Array const &src );
        Array& operator=( Array const &src );
        ~Array();
        T size();

};