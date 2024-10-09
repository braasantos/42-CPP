#pragma once 

#include <iostream>
// #include <string.h>
#include <cstdlib>
#include <ctime>
#include <exception>

template <typename T>
class Array
{
    // private:
    public:
        unsigned int _size;
        T *_arr;
        Array(): _size(0)
        {
            _arr = new T[_size];
        }
        Array(unsigned int n)  : _size(n), _arr(new T[n]()) {};
        Array(Array const &src)
        {
            this->_size = src._size;
			this->_arr = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
			{
				this->_arr[i] = src._arr[i];
			} 
        }
        Array& operator=(Array const &src)
        {
            if (this != &src)
            {
                delete []_arr;
                _size = src._size;
                if (_size > 0)
                {
                    _arr = new T[_size];
                    for (int i = 0; i < _size; i++)
                        _arr[i] = src.arr[i];
                }
            }
            return *this;
        }
        ~Array()
        {
            delete[] this->_arr;
        }
        int size()
        {
            return this->_size; 
        }
        T &operator[](unsigned int i)
        {
            if (i >= this->_size)
                throw(std::out_of_range("Array index out of bounds!"));
            else
                return this->_arr[i];
        }
};