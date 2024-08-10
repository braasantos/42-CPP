#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap trapp("batman");
    ScavTrap clapp("jocker");
    while (trapp.get_hitPo() > 0 && trapp.get_enePo() > 0)
    {
        trapp.attack("jocker");
        if (clapp.get_attDam() == 20)
            clapp.beRepaired(1);
    }
    trapp.guardGate();
    // trapp.takeDamage(10);
    // clapp.attack("braulio");
    // clapp.takeDamage(10);
    // clapp.beRepaired(1);
    return 0;
}