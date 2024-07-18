#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 0 || N < -2147483648 || N > 2147483647)
    {
        std::cout << "Not a valid number\n";
        return NULL;
    }
    Zombie *newzombie = NULL;
    try
    {
        newzombie = new Zombie[N];
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "ERROR: " <<  e.what() << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++)
    {
        newzombie[i].set_name(name);
    }
    return newzombie;
}