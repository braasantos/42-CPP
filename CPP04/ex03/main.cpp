
// only works but you cannot instatiate  AAnimal directly 
#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

//	polymorphism a user amateria to refer to different types of materia like cure and ice


//	Polymorphism is not just about creating a pointer to a base class. It’s about the ability 
//	of that pointer to point to different derived classes, and most importantly, about calling 
//	ethods on that pointer that behave differently depending on the actual derived class type.

//	Abstract classes are classes that cannot be instantiated on their own and are meant to be subclassed.
//	An abstract class typically contains one or more pure virtual functions (functions that have no
//implementation in the base class and must be overridden by derived classes).

//	An interface is a class that has no member variables and all of its functions are pure virtual functions.
//	Interfaces are used to define a contract that other classes must follow. If a class implements an interface,
//	it must provide an implementation for all of the functions declared in the interface.

//	An abstract class can have member variables and member functions with implementations, while an interface cannot.
//	An abstract class can have constructors, while an interface cannot.


int main()
{
    IMateriaSource* src = new MateriaSource();	// pointer to imateriasource
												//	but the object is of type MateriaSource
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}

// int main()
// {
// 	{
// 		std::cout << "------------1--------------" << std::endl;
// 		AMateria *cure = new Cure("cure");
// 		AMateria *ice = new Ice("ice");
// 		std::cout << cure->getType() << std::endl;
// 		std::cout << ice->getType() << std::endl;

//     	std::cout << "-------------" << std::endl;

// 		AMateria *cloned_cure;
// 		AMateria *cloned_ice;
// 		cloned_cure = cure->clone();
// 		cloned_ice = ice->clone();

// 		std::cout << cloned_cure->getType() << std::endl;
// 		std::cout << cloned_ice->getType() << std::endl;

// 		delete cloned_cure;
// 		delete cloned_ice;
// 		delete cure;
// 		delete ice;

// 	}
//     std::cout << "-------------2-------------" << std::endl;
// 	{
// 		ICharacter *test = new Character("batman");
// 		ICharacter *test2 = new Character("jocker");

// 		AMateria *cure1 = new Cure();
// 		AMateria *ice1 = new Ice();
// 		AMateria *cure2 = new Cure();
// 		AMateria *ice2 = new Ice();

// 		std::cout << test->getName() << std::endl; 
// 		std::cout << test2->getName() << std::endl; 

// 		test->equip(cure1);
// 		test->equip(ice1);
// 		test->equip(cure2);
// 		test->equip(ice2);
// 		test->use(0, *test2);
// 		test->use(1, *test2);
// 		test->use(2, *test2);
// 		test->use(3, *test2);

// 		test->unequip(0);
// 		test->unequip(1);
// 		test->unequip(2);
// 		test->unequip(3);

// 		test->use(0, *test2);

// 		delete test;
// 		delete test2;
// 		delete cure1;
// 		delete ice1;
// 		delete cure2;
// 		delete ice2;
// 	}

//     std::cout << "-----------3--------------" << std::endl;
// 	{
// 		IMateriaSource* src = new MateriaSource();

// 		src->learnMateria(new Ice());
// 		src->learnMateria(new Cure());
	
// 		ICharacter* me = new Character("me");
// 		AMateria* tmp;

// 		tmp = src->createMateria("ice");
// 		me->equip(tmp);
// 		tmp = src->createMateria("cure");
// 		me->equip(tmp);

// 		ICharacter* bob = new Character("bob");

// 		me->use(0, *bob);
// 		me->use(1, *bob);

// 		delete bob;
// 		delete me;
// 		delete src;
// 		return 0;
// 	}
// }