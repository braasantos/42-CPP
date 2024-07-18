#include "HumanB.hpp"

void HumanB::attack(void)
{
    if (!this->weapon)
        std::cout << BLUE << this->name  << RESET << " attacks with their hands" << std::endl;
    else
        std::cout << BLUE << this->name << RESET << " attacks with their " << RED << this->weapon->getType() << RESET << std::endl;
}
HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
    // this->name = name;
    // this->weapon = NULL;
    set_name(name);
    std::cout << "HumanB: " << BLUE << name << RESET << " initialized with no weapon" << std::endl << std::endl;
}
HumanB::~HumanB(void)
{
    std::cout << "HumanB "<< BLUE << this->name << RESET << " died :(\n";
}

void HumanB::set_name(std::string input)
{
    this->name = input;
}
void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}