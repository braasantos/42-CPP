#include "Dog.hpp"

Dog::Dog()  : type("Dog")
{
    std::cout << "Wait you adopted a " << this->type << " 🐶" << std::endl;
}
Dog::Dog(std::string name) :type(name)
{

}
Dog::~Dog()
{
    std::cout << this->type << "ran away 🐾" << std::endl;
}
Dog::Dog(const Dog& otherClass) : type(otherClass.type)
{
    std::cout << "Copy Constructor was called" << std::endl;
}

Dog& Dog::operator=(const Dog& otherClass)
{
    std::cout << "Copy Assignment copy operator was called" << std::endl;
    if (this != &otherClass)
        return *this;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << this->type << " is barking ♪♪*(´0`)*♪♪" << std::endl;
}
std::string Dog::getType() const
{
    return this->type;
}