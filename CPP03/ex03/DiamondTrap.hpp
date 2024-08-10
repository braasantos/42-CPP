#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define BRIGHT_YELLOW "\033[93m"
#define RESET "\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap& otherClass);
        DiamondTrap& operator=(const DiamondTrap& other);
        void whoAmI();

};