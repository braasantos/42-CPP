#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Wait you adopted a " << this->type << " 🐶" << std::endl;
    this->brain = new Brain();
}
Dog::Dog(std::string name) :Animal()
{
    this->type = name;
    std::cout << "Wait you adopted a " << this->type << " 🐶" << std::endl;
    this->brain = new Brain();

}
Dog::~Dog()
{
    std::cout << this->type << " ran away 🐾" << std::endl;
    delete this->brain;
}
Dog::Dog(const Dog& otherClass) : Animal(otherClass)
{
    *this = otherClass;
    std::cout << "Copy Constructor was called" << std::endl;
}

Dog& Dog::operator=(const Dog& otherClass)
{
    std::cout << "Copy Assignment copy operator was called" << std::endl;
    if (this != &otherClass)
    {
        this->type = otherClass.type;
        Brain* newBrain = new Brain(*otherClass.brain);
	    delete this->brain;
	    this->brain = newBrain;
    }
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
Brain* Dog::getBrain( void )
{
    return brain;
}