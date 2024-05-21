#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
    Zombie *newZombie = new Zombie(name);
    return newZombie;
}

Zombie::~Zombie(void)
{
    std::cout << name << " says: I'm outta here!" << std::endl;
}

Zombie::Zombie()
{
    this->name = "Batman";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

