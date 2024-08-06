#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _hitPoints = 100;
    _enePoints = 100;
    _attDamage = 30;
    std::cout  << GREEN << "FragTrap " << RESET << "Default Constructor was called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _enePoints = 100;
    _attDamage = 30;
    std::cout << "Just created " << GREEN << "FragTrap " << RESET << this->_name << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << GREEN << "FragTrap " << RESET <<  "Destructor was called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& otherClass)
{
    this->_name = otherClass._name;
    this->_hitPoints = otherClass._hitPoints;
    this->_enePoints = otherClass._enePoints;
    this->_attDamage = otherClass._attDamage;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_enePoints = other._enePoints;
        this->_attDamage = other._attDamage;
    }
    return *this;
}
void FragTrap::highFivesGuys(void)
{
    if (this->_enePoints <= 0)
        std::cout << GREEN << "FragTrap "<< RESET << this->_name << "doesnt have the energy to give a positive high fives" << std::endl;
    else
        std::cout << GREEN << "FragTrap " << RESET << this->_name << "wants to give you a positive high five" << std::endl;
}