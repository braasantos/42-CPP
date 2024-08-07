#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << BRIGHT_YELLOW << "DiamondTrap " << RESET << " Default constructor was called" << std::endl;
    this->ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_enePoints = ScavTrap::_enePoints;
    this->_attDamage = FragTrap::_attDamage;
}
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    std::cout << BRIGHT_YELLOW << "DiamondTrap " << RESET << this->_name << " was created" << std::endl;
    this->_name = name;
    this->ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_enePoints = ScavTrap::_enePoints;
    this->_attDamage = FragTrap::_attDamage;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << BRIGHT_YELLOW << "DiamondTrap" << RESET << " was called" << std::endl;
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