#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
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