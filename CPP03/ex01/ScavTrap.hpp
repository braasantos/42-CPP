#pragma once
#include "ClapTrap.hpp"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ScavTrap : public ClapTrap
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