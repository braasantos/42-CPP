#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;//should not create a leak
    // delete i;
int main()
{
    int size = 10;
    Animal *animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();
    for (int i = 0; i < size; ++i)
        delete animals[i];
    return 0;
}

// int main()
// {
// 	Cat* j = new Cat();
// 	Cat* i = new Cat(*j);
// 	Cat* k = new Cat();

// 	*k = *j;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();

// 	std::cout << "Brain of j " << j->getBrain() << std::endl;
// 	std::cout << "Brain of i " << i->getBrain() << std::endl;
// 	std::cout << "Brain of k " << k->getBrain() << std::endl;

// 	delete k;
// 	delete j;
// 	delete i;
// }