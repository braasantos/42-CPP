#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints= 100;
    _enePoints = 50;
    _attDamage = 20;
    std::cout << RED << "ScavTrap " << RESET << "Default Constructor was called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
    _hitPoints= 100;
    _enePoints = 50;
    _attDamage = 20;
}
ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap " << RESET << "Destructor was called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& otherClass)
{
    this->_name = otherClass._name;
    this->_hitPoints = otherClass._hitPoints;
    this->_enePoints = otherClass._enePoints;
    this->_attDamage = otherClass._attDamage;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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
int checkClapTrap(ScavTrap &clap)
{
    if (clap.get_hitPo() <= 0)
    {
        std::cout << RED << "ScavTrap " << RESET << clap.get_name() << " is out of hit points to do anything\n";
        return 1;
    }
    else if (clap.get_enePo() <= 0)
    {
        std::cout << RED << "ScavTrap " << RESET << clap.get_name() << " is out of energy to do anything\n";
        return 1;
    }
    return 0;
}
void ScavTrap::attack(const std::string& target)
{
    if (checkClapTrap(*this))
        return ;
    else
        std::cout << RED << "ScavTrap " << RESET << this->_name << " attacks " << target << std::endl;
    this->_enePoints--;
}

void ScavTrap::guardGate()
{
    std::cout << RED << "ScavTrap " << RESET << this->get_name() << " is now in Gate keeper mode" << std::endl;
}