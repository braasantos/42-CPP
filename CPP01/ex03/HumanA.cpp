#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :name (name), weapon (weapon)
{
    std::cout <<"HumanA: " << name << " initialized with weapon " << std::endl << std::endl;
}
HumanA::~HumanA(void)
{
    std::cout << "im out\n";
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->weapon.getType() << std::endl;
}