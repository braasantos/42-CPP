#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::set_n(int input)
{
    N = input;
}
int Zombie::get_n(void)
{
    return N;
}
std::string Zombie::get_name( void )
{
    return this->name;
}
void Zombie::set_name(std::string input)
{
    this->name = input;
}

Zombie::~Zombie(void){}
Zombie::Zombie(void){}