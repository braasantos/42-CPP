#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
    // std::cout << "Ice constructor was called" << std::endl;
}
Ice::Ice( std::string type )
{
    // std::cout << "Ice constructor was called" << std::endl;
    this->type = type;
}
Ice::~Ice()
{
    // std::cout << "Ice destructor was called" << std::endl;
}
Ice::Ice( const Ice& otherClass ) : AMateria(otherClass)
{
    this->type = otherClass.type;
    *this = otherClass;
}
Ice& Ice::operator=( const Ice& otherClass )
{
    if (this != &otherClass)
        return *this;
    return *this;
}

// std::string const & Ice::getType() const
// {
//     return this->type;
// }

AMateria* Ice::clone( void ) const
{
    // std::cout << "Ice clone was called" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}