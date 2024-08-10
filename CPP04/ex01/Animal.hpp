#pragma once 

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string name);
        virtual ~Animal();
        Animal(const Animal& otherClass);
        Animal& operator=(const Animal& otherClass);
        virtual void makeSound() const;
        virtual std::string getType() const;
};