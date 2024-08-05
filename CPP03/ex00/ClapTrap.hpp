#pragma once
#include <iostream>

class ClapTrap
{
    private:
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
        // void set_hitPo(int number);
        // void set_enePo(int number);
        // void set_attDam(int number);
        int get_hitPo(void);
        int get_enePo(void);
        int get_attDam(void);
};