#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    private:
        std::string type;
        Brain *brain;
    public:
        Dog();
        Dog(std::string name);
        ~Dog();
        Dog(const Dog& otherClass);
        Dog& operator=(const Dog& otherClass);
        void makeSound() const;
        std::string getType() const;
};