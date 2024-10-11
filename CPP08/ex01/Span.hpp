#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &src);
        Span& operator=(Span const &src);
        ~Span();
        void addNumber(int n);
        int longestSpan();
        int shortestSpan();
        void addAutomatic();
};