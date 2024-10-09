#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNum = rand() % 3 + 1;
    switch (randomNum)
    {
        case 1:
            return dynamic_cast<Base *>(new A());
        case 2:
            return dynamic_cast<Base *>(new B());
        default:
            return dynamic_cast<Base *>(new C());
        
    }
}

//  A type of casting in C++ that checks if a pointer or reference to a base class 
//  can safely be converted to a pointer or reference to a derived class.
void identify(Base* p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "UNKNOWN TYPE" << std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(...)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(...)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...)
    {
    }
}