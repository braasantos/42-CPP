#include "ClapTrap.hpp"

std::string ClapTrap::get_name(void)
{
    return this->_name;
}
int ClapTrap::get_hitPo(void)
{
    return this->_hitPoints;
}
int ClapTrap::get_enePo(void)
{
    return this->_energyPoints;
}
int ClapTrap::get_attDam(void)
{
    return this->_attackDamage;
}

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << BLUE << "ClapTrap " << RESET <<  "Constructor was created" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << BLUE << "ClapTrap " << RESET << this->_name << " was created" << std::endl;

}
ClapTrap::~ClapTrap()
{
    std::cout << BLUE << "ClapTrap " << RESET << "Destructor was called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& otherClass)
{
    this->_name = otherClass._name;
    this->_hitPoints = otherClass._hitPoints;
    this->_energyPoints = otherClass._energyPoints;
    this->_attackDamage = otherClass._attackDamage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

int checkClapTrap(ClapTrap &clap)
{
    if (clap.get_hitPo() <= 0)
    {
        std::cout << BLUE << "ClapTrap " << RESET << clap.get_name() << " is out of hit points to do anything\n";
        return 1;
    }
    else if (clap.get_enePo() <= 0)
    {
        std::cout << BLUE << "ClapTrap " << RESET << clap.get_name() << " is out of energy to do anything\n";
        return 1;
    }
    return 0;
}
void ClapTrap::attack(const std::string& target)
{
    if (checkClapTrap(*this))
        return ;
    else
        std::cout << BLUE << "ClapTrap " << RESET << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
     if (checkClapTrap(*this))
        return ;
    this->_hitPoints -= amount;
    std::cout << BLUE << "ClapTrap " << RESET << this->_name <<" was attacked causing " << this->_attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
     if (checkClapTrap(*this))
        return ;
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << BLUE << "ClapTrap " << RESET << this->_name << " was repaired!" << std::endl;
}