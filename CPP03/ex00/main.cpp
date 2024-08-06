#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trapp("braulio");
    ClapTrap clapp("hugo");
    trapp.attack("hugo");
    trapp.takeDamage(10);
    trapp.beRepaired(1);
    clapp.attack("braulio");
    clapp.takeDamage(10);
    clapp.beRepaired(1);
    return 0;
}