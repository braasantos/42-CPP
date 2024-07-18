#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    Zombie *newzombie;
    int n = 5;
    newzombie = zombieHorde(n, "Batman");
    if (newzombie == NULL)
        return 0;
    for(int i = 0; i < n; i++)
        newzombie[i].announce();
    delete [] newzombie;
}