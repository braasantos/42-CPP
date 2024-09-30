#pragma once 

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        std::string type;
        Brain *brain;
    public:
        Cat();
        Cat(std::string name);
        ~Cat();
        Cat(const Cat& otherClass);
        Cat& operator=(const Cat& otherClass);
        void makeSound() const;
        std::string getType() const;
        Brain* getBrain( void );

};