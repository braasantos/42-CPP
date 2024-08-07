#pragma once 

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    protected:
        std::string type;
    public:
        Cat();
        Cat(std::string name);
        ~Cat();
        Cat(const Cat& otherClass);
        Cat& operator=(const Cat& otherClass);
};