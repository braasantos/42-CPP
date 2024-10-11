#pragma once 

#include <iostream>
#include <stack>
#include <algorithm>


// need to inherit from std::stack to aceed functions like pop push top etc
template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack<T> const &src);
        MutantStack& operator=(MutantStack<T> const &src);
        ~MutantStack();
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};
#include "MutantStack.tpp"