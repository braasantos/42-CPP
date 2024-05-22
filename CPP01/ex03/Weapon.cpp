#include "Weapon.hpp"

const std::string& Weapon::getType(void)
{
    return this->type;
}
void Weapon::setType(std::string input)
{
    this->type = input;
}

Weapon::Weapon(std::string name)
{
    std::cout << std::endl << "Weapon created: " << name << std::endl;
}
Weapon::~Weapon()
{
    std::cout << std::endl << "Weapon " << this->type << " cleaned." << std::endl;
}
Weapon::Weapon(){}