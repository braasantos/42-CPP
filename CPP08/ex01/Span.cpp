#include "Span.hpp"

Span::Span(): N(0){}

Span::Span(unsigned int n){this->N = n;}

Span::Span(Span const &src)
{
    this->N = src.N;
    *this = src;
}

Span& Span::operator=(Span const &src)
{
    if (this != &src)
    {
        this->N = src.N;
        return *this;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int n)
{
    if (this->vec.size() <= this->N)
        vec.push_back(n);
    else
        throw(std::out_of_range("Cannot add more numbers"));
}
int Span::longestSpan()
{
    if (this->vec.size() < 1)
        throw(std::out_of_range("No span found"));
    std::sort(this->vec.begin(), this->vec.end());
    int max = *std::max_element(this->vec.begin(), this->vec.end());
    int min = *std::min_element(this->vec.begin(), this->vec.end());
    return (max - min);
}

int Span::shortestSpan()
{
    if (this->vec.size() < 1)
        throw(std::out_of_range("No span found"));
    std::sort(this->vec.begin(), this->vec.end());
    int max = *std::max_element(this->vec.begin(), this->vec.end());
    int min = *std::min_element(this->vec.begin(), this->vec.end());
    int span = max - min;
    int oldSpan = INT_MAX;
    for (size_t i = 0; i <= this->vec.size(); i++)
    {
        for (size_t j = i + 1; j <= this->vec.size(); j++)
        {
            if (this->vec[i] < this->vec[j])
                oldSpan = this->vec[j] - this->vec[i];
            if (oldSpan < span)
                span = oldSpan;
        }
    }
    return span;
}

void Span::addAutomatic()
{
    size_t i = this->N;
    if (this->N < 1)
        throw(std::out_of_range("Cannot add more numbers"));
    while (i)
    {
        const int value = rand();
        vec.push_back(value); // Add an element
        i--;
    }
}