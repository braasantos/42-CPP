#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
    std::cout << "Mutant stack created" << std::endl;
}
template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>()
{
    std::stack<T>::operator=(src);
}
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src)
{
    if (this != &src)
        std::stack<T>::operator=(src);
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "Mutant stack deleted" << std::endl;
}

//  c is a convention used in the implementation of std::stack 
//  to refer to the underlying 
//  container that holds the elements of the stack

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
}