#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>
{}
template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &scr): std::stack<T>
{

}
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &scr)
{

}

template<typename T>
MutantStack<T>::~MutantStack()
{

}

// template<typename T>
// typename std::stack<T>::iterator::iterator MutantStack<T>::begin()
// {
//     return this->c.begin();
// }

// template<typename T>
// typename std::stack<T>::iterator::iterator MutantStack<T>::end()
// {
//     return this->c.end();
// }

// template<typename T>
// typename std::stack<T>::const_iterator::iterator MutantStack<T>::begin() const
// {
//     return this->c.begin();
// }

// template<typename T>
// typename std::stack<T>::const_iterator::iterator MutantStack<T>::end() const
// {
//     return this->c.end();
// }