#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Wait you adopted a " << this->type << " 🐱"<< std::endl;
    this->brain = new Brain();
}
Cat::Cat(std::string name) : Animal()
{
    this->type = name;
    this->brain = new Brain();
}
Cat::~Cat()
{
    std::cout << this->type << " ran away 🐾" << std::endl;
    delete this->brain;
}
Cat::Cat(const Cat& otherClass) : Animal(otherClass)
{
    *this = otherClass;
    std::cout << "Copy Constructor was called" << std::endl;
}

Cat& Cat::operator=(const Cat& otherClass)
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

void Cat::makeSound() const
{
    std::cout << this->type << " is meowing ♪♪*(´0`)*♪♪" << std::endl;
}
std::string Cat::getType() const
{
    return this->type;
}

Brain* Cat::getBrain( void )
{
    return brain;
}