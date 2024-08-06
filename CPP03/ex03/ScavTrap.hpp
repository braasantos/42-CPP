#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& otherClass);
        ScavTrap& operator=(const ScavTrap& other);
        void attack(const std::string& target);
        void guardGate();
};