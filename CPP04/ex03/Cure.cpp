#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
    // std::cout << "Cure constructor was called" << std::endl;
}
Cure::Cure( std::string type )
{
    // std::cout << "Cure constructor was called" << std::endl;
    this->type = type;
}
Cure::~Cure()
{
    // std::cout << "Cure destructor was called" << std::endl;
}
Cure::Cure( const Cure& otherClass ) : AMateria(otherClass)
{
   this->type = otherClass.type;
   *this = otherClass;
}

Cure& Cure::operator=( const Cure& otherClass )
{
    if (this != &otherClass)
        return *this;
    return *this;
}

// std::string const & Cure::getType() const
// {
//     return this->type;
// }

AMateria* Cure::clone( void ) const
{
    // std::cout << "Cure clone was called" << std::endl;
    return new Cure(*this);
}
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}