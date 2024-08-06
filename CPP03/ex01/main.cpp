#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap trapp("braulio");
    ScavTrap clapp("hugo");
    while (trapp.get_hitPo() > 0 && trapp.get_enePo() > 0)
    {
        trapp.attack("hugo");
        if (clapp.get_attDam() == 0)
            clapp.beRepaired(1);
    }
    // trapp.takeDamage(10);
    // clapp.attack("braulio");
    // clapp.takeDamage(10);
    // clapp.beRepaired(1);
    return 0;
}