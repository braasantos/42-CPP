#include "ClapTrap.hpp"


int ClapTrap::get_hitPo(void)
{
    return this->_hitPoints;
}
int ClapTrap::get_enePo(void)
{
    return this->_enePoints;
}
int ClapTrap::get_attDam(void)
{
    return this->_attDamage;
}

ClapTrap::ClapTrap(): _hitPoints(10)
{
    std::cout << "Constructor was created" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << this->_name << " was created" << std::endl;

}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor was called" << std::endl;
}
// ClapTrap::ClapTrap(const ClapTrap& otherClass)
// {

// }
// ClapTrap::ClapTrap& operator=(const ClapTrap& other)
// {

// }
void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0)
        std::cout << "ClapTrap is out of hit points to do anything\n";
    else
        std::cout << "ClapTrap" << this->_name << "attacks" << target << ", causing" << get_attDam() << "points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    this->_attDamage = -amount;
    std::cout << "ClapTrap <name> attacks <target>, causing <damage> points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitPoints = -amount;
    std::cout << "ClapTrap <name> attacks <target>, causing <damage> points of damage!" << std::endl;
}