#pragma once 

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string name);
        ~Animal();
        Animal(const Animal& otherClass);
        Animal& operator=(const Animal& otherClass);
        void makeSound();
        std::string getType();
};