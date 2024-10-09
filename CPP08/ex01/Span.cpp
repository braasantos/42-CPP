#include "Span.hpp"

Span::Span(): N(0){}

Span::Span(unsigned int n){this->N = n}

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

void Span::addNumber()
{

}
int Span::longestSpan()

int Span::shortestSpan()

void Span::addAutomatic()
{
    
}