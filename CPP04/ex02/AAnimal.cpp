#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "Animal was addopted ╏つ ͜ಠ ‸ ͜ಠ ╏つ" << std::endl; 
}
AAnimal::AAnimal(std::string name) : type(name)
{
}
AAnimal::~AAnimal()
{
    std::cout << "Animal ran away （ ◞ ‸◟。 ）" << std::endl; 
}
AAnimal::AAnimal(const AAnimal& otherClass) : type(otherClass.type)
{

}
AAnimal& AAnimal::operator=(const AAnimal& otherClass)
{
    if (this != &otherClass)
        return *this;
    return *this;
}
void AAnimal::makeSound() const
{
    std::cout << this->type << " is making a sound ♪♪*(´0`)*♪♪" << std::endl;
}
std::string AAnimal::getType() const
{
    return this->type;
}