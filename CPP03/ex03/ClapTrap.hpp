#pragma once
#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _enePoints;
        int _attDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& otherClass);
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string get_name(void);
        int get_hitPo(void);
        int get_enePo(void);
        int get_attDam(void);
};