#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor is called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string name) :type(name)
{
    std::cout << "WrongAnimal Constructor is called" << std::endl;

}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor is called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& otherClass)
{
    this->type = otherClass.type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& otherClass)
{
    if (this != &otherClass)
        return *this;
    return *this;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal is making a sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return this->type;
}