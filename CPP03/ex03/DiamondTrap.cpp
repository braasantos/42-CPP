#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("undefined")
{
    std::cout << BRIGHT_YELLOW << "DiamondTrap " << RESET << " Default constructor was called" << std::endl;
    this->ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage =  30;

}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    std::cout << BRIGHT_YELLOW << "DiamondTrap " << RESET << this->_name << " was created" << std::endl;
    this->ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << BRIGHT_YELLOW << "DiamondTrap" << RESET << " Destructor was called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& otherClass)
{
    *this = otherClass;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        FragTrap::_name = other._name;
        ScavTrap::_name = other._name;
        _name = other._name;
        }
        return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << BRIGHT_YELLOW << "DiamondTrap " << RESET "is called " << this->_name << BLUE << " ClapTrap " << RESET "is called " << ClapTrap::_name << std::endl;
}