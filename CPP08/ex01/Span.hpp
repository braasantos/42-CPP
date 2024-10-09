#pragma once
#include <iostream>

class Span
{
    private:
        unsigned int N;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &src);
        Span& operator=(Span const &src);
        ~Span();
        void addNumber();
        int longestSpan();
        int shortestSpan();
        void addAutomatic();
};