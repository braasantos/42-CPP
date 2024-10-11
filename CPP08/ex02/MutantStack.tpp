#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
    std::cout << "Mutant stack created" << std::endl;
}
template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src)
{
    this = &src;
}
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src)
{
    if (this != &src)
        return *this;
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "Mutant stack deleted" << std::endl;
}

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