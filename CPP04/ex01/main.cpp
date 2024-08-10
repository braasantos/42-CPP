#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;//should not create a leak
    // delete i;
int main()
{

    Animal *dog = NULL;
    try
    {
        dog = new Dog("Stitch");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    dog->makeSound();
    delete dog;
    return 0;
}