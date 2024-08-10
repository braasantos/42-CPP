#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
    DiamondTrap trapp("batman");
    DiamondTrap clapp("jocker");
    while (trapp.get_hitPo() > 0 && trapp.get_enePo() > 0)
    {
        trapp.attack("jocker");
        clapp.takeDamage(1);
        if (trapp.get_attDam() == 20)
            clapp.beRepaired(1);
    }
    trapp.attack("jocker");
    trapp.whoAmI();
    clapp.whoAmI();
    return 0;
}
