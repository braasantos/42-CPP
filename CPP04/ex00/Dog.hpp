#pragma once 

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    protected:
        std::string type;
    public:
        Dog();
        Dog(std::string name);
        ~Dog();
        Dog(const Dog& otherClass);
        Dog& operator=(const Dog& otherClass);

};