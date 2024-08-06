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

ClapTrap::ClapTrap() : _hitPoints(10), _enePoints(10), _attDamage(0)
{
    std::cout << "Constructor was created" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _enePoints(10), _attDamage(0)
{
    std::cout << this->_name << " was created" << std::endl;

}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor was called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& otherClass)
{
    this->_name = otherClass._name;
    this->_hitPoints = otherClass._hitPoints;
    this->_enePoints = otherClass._enePoints;
    this->_attDamage = otherClass._attDamage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_enePoints = other._enePoints;
        this->_attDamage = other._attDamage;
        return *this;
    }
    return *this;
}

int checkClapTrap(int points)
{
    if (points <= 0)
        return 1;
    return 0;
}
void ClapTrap::attack(const std::string& target)
{
    if (checkClapTrap(this->_hitPoints))
    {
        std::cout << "ClapTrap is out of hit points to do anything\n";
        return ;
    }
    else
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << get_hitPo() << " points of damage!" << std::endl;
    this->_enePoints--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
     if (checkClapTrap(this->_hitPoints))
    {
        std::cout << "ClapTrap is out of hit points to do anything\n";
        return ;
    }
    this->_attDamage -=amount;
    std::cout << "ClapTrap " << this->_name <<" was attacked causing " << this->_attDamage << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
     if (checkClapTrap(this->_hitPoints))
    {
        std::cout << "ClapTrap is out of hit points to do anything\n";
        return ;
    }
    this->_hitPoints -=-amount;
    std::cout << "ClapTrap " << this->_name << " was repaired!" << std::endl;
}