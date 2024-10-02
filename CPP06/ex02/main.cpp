#include "Base.hpp"
#include "utils.hpp"

int main(void)
{
    Base *baseClass;
    baseClass = generate();
    identify(baseClass);
    identify(*baseClass);
    delete baseClass;
}