#include "Zombie.hpp"

#include <iostream>
#include <string>

int main(void)
{
    Zombie *zombie;
    zombie = zombie->newZombie("braulio");
    zombie->announce();
    delete zombie;
    return 0;
}
