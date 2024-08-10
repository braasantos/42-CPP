#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trapp("batman");
    ClapTrap clapp("jocker");
    while (trapp.get_hitPo() > 0 && trapp.get_enePo() > 0)
    {
        trapp.attack("jocker");
        if (clapp.get_attDam() == 0)
            clapp.beRepaired(1);
    }
    // trapp.takeDamage(10);
    // clapp.attack("braulio");
    // clapp.takeDamage(10);
    // clapp.beRepaired(1);
    return 0;
}