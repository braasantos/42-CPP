#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal was addopted ╏つ ͜ಠ ‸ ͜ಠ ╏つ" << std::endl; 
}
Animal::Animal(std::string name) : type(name)
{
}
Animal::~Animal()
{
    std::cout << "Animal ran away （ ◞ ‸◟。 ）" << std::endl; 
}
Animal::Animal(const Animal& otherClass) : type(otherClass.type)
{

}
Animal& Animal::operator=(const Animal& otherClass)
{
    if (this != &otherClass)
        return *this;
    return *this;
}
void Animal::makeSound() const
{
    std::cout << this->type << " is making a sound ♪♪*(´0`)*♪♪" << std::endl;
}
std::string Animal::getType() const
{
    return this->type;
}