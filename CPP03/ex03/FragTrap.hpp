#pragma once
#include "ClapTrap.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"
class FragTrap : virtual public ClapTrap // making sure only one copy of the base
{
    public:
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& otherClass);
        FragTrap& operator=(const FragTrap& other);
        void highFivesGuys(void);
};

//without special handling the the diamond would have 2 copies of a