#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // created objects of the derived class but store them in a base class pointer
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << "-----------------------------------------" << std::endl;

    const WrongAnimal* animal = new WrongCat("braulio");
    animal->makeSound();
    delete animal;

    std::cout << "-----------------------------------------" << std::endl;
    // SLICING
    WrongAnimal Animal = WrongCat("braulio");
    Animal.makeSound();
    // when a derived class is passed by value to the base the derived 
    // is sliced on only the base class remain 
    return 0;
}