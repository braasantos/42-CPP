#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;//should not create a leak
    // delete i;

    Animal *dog = NULL;
    try
    {
        dog = new Dog[5];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // for (int i = 0; i < 5; i++)
        // dog[1].makeSound();
    delete[] dog;
    return 0;
}