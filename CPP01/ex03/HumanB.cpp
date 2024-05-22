#include "HumanB.hpp"

void HumanB::attack(void)
{
    if (!this->weapon)
        std::cout << this->name << " attacks with their hands" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
HumanB::HumanB(std::string name)
{
    std::cout << "HumanB: " << name << " initialized with no weapon" << std::endl << std::endl;
}
HumanB::~HumanB(void){}

void HumanB::set_name(std::string input)
{
    this->name = input;
}
void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}