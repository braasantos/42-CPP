#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 0 || N < -2147483648 || N > 2147483647)
    {
        std::cout << "Not a valid number\n";
        return NULL;
    }
    Zombie *newzombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        newzombie[i].set_name(name);
    }
    return newzombie;
}