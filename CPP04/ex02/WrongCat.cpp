#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Constructor is called" << std::endl;
}
WrongCat::WrongCat(std::string name) :type(name)
{
    std::cout << "WrongCat Constructor is called" << std::endl;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Constructor is called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& otherClass) : WrongAnimal(otherClass)
{
  this->type = otherClass.type;
}
WrongCat& WrongCat::operator=(const WrongCat& otherClass)
{
    if (this != &otherClass)
        return *this;
    return *this;
}
void WrongCat::makeSound() const
{
    std::cout << "WrongCat is making a sound" << std::endl;
}
std::string WrongCat::getType() const
{
    return this->type;
}