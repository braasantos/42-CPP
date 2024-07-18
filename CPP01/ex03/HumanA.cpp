#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
    this->name = name;
    this->weapon = weapon;
    std::cout << "HumanA: " << BLUE << name << RESET <<" initialized with weapon : " << RED <<  this->weapon.getType() << RESET << std::endl << std::endl;
}
HumanA::~HumanA(void)
{
    std::cout << "HumanA " << BLUE <<  this->name << RESET << " died :(\n";
}

void HumanA::attack()
{
    std::cout << BLUE << this->name << RESET << " attacks with their "<< RED << this->weapon.getType() << RESET << std::endl;
}