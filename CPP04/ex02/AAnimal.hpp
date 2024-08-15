#pragma once 

#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string name);
        virtual ~AAnimal();
        AAnimal(const AAnimal& otherClass);
        AAnimal& operator=(const AAnimal& otherClass);
        virtual void makeSound() const = 0; // pure virtual function 
        virtual std::string getType() const;
};