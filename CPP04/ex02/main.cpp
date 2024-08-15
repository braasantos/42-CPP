#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// only works but you cannot instatiate  AAnimal directly 

int main()
{
    // int size = 10;
    // AAnimal *animals[size];

    // for (int i = 0; i < size / 2; i++)
    //     animals[i] = new Dog();
    // for (int i = size / 2; i < size; i++)
    //     animals[i] = new Cat();
    // for (int i = 0; i < size; ++i)
    //     animals[i]->makeSound();
    // for (int i = 0; i < size; ++i)
    //     delete animals[i];
    AAnimal *animals = new Dog();
    animals->makeSound();
    return 0;
}