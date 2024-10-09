#include "Array.hpp"

Array::Array()
{
    T newArr[0];
}
Array::Array( T n )
{
     new T newArr[n];
}
Array::Array( Array const &src )
{
    this = &src;
}
Array& Array::operator=( Array const &src )
{
    if (*this != src)
        return *this;
    return *this;
}
Array::~Array()
{
    std::cout << "Program is over" << std::endl;
}
T Array::size()
{
    return this->n;
}