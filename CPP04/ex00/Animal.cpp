#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor was called " << std::endl; 
}
Animal::Animal(std::string name)
{

}
Animal::~Animal()
{
    std::cout << "Destructor was called " << std::endl; 
}
Animal::Animal(const Animal& otherClass)
{

}
Animal& Animal::operator=(const Animal& otherClass)
{

}
void Animal::makeSound()
{

}
std::string Animal::getType()
{
    return this->type;
}