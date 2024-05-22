#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " says: I'm outta here!" << std::endl;
}

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
{
    this->name = name;
}
