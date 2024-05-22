#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    try
    {
        Zombie *newZombie = new Zombie(name);
        return newZombie;
    }
    catch(std::bad_alloc e)
    {
        std::cerr << e.what() << '\n';
    }
    return NULL;
}

    // The function uses new to allocate memory for the 
    // Zombie object on the heap, not the stack. Heap allocation 
    // persists until the memory is explicitly deallocated using delete.
    // Stack allocation, on the other hand, is automatically
    //  managed and the memory is released when the scope in which 
    //  the variable was defined ends.