#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
    DiamondTrap trapp("braulio");
    DiamondTrap clapp("hugo");
    // while (trapp.get_hitPo() > 0 && trapp.get_enePo() > 0)
    {
        trapp.attack("hugo");
        // if (clapp.get_attDam() == 30)
            // clapp.beRepaired(1);
    }
    trapp.attack("hugo");
    trapp.whoAmI();
    clapp.whoAmI();
    // trapp.takeDamage(10);
    // clapp.attack("braulio");
    // clapp.takeDamage(10);
    // clapp.beRepaired(1);
    return 0;
}