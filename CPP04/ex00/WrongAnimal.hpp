#pragma once

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string name);
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& otherClass);
        WrongAnimal& operator=(const WrongAnimal& otherClass);
        void makeSound() const;
        std::string getType() const;
};