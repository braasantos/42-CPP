#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout  << GREEN << "FragTrap " << RESET << "Default Constructor was called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
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
    this->_energyPoints = otherClass._energyPoints;
    this->_attackDamage = otherClass._attackDamage;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}
void FragTrap::highFivesGuys(void)
{
    if (this->_energyPoints <= 0)
        std::cout << GREEN << "FragTrap "<< RESET << this->_name << "doesnt have the energy to give a positive high fives :(" << std::endl;
    else
        std::cout << GREEN << "FragTrap " << RESET << this->_name << "wants to give you a positive high five :)" << std::endl;
}