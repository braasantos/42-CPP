#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(int ac, char **av)
{
    if (ac > 1 && ac <= 5)
    {
        randomChump(av[1]); // stack
        for (int i = 2; av[i]; i++)
        {
            Zombie *newzombie;
            newzombie = newZombie(av[i]); // heap
            newzombie->announce();
            delete newzombie;
        }
    }
    else
        std::cout << "Invalid args\n";
    return 0;
}
