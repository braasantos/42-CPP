#include "Cure.hpp"

Cure::Cure() :type ("cure")
{

}
Cure::Cure( std::string type ) :type("cure")
{

}
Cure::~Cure()
{

}
Cure::Cure( const Cure& otherClass )
{
   this->type = otherClass.type;
}

Cure& Cure::operator=( const Cure& otherClass )
{
    if (this != &otherClass)
        return *this;
    return *this;
}

Cure& Cure::Clone( void )
{

}
void Cure::use(ICharacter& target)
{
    // std::cout << "* heals " << target << "’s wounds *" << std::endl;
}