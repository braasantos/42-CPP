#include "AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria Constructor was called" << std::endl;
}
AMateria::AMateria(std::string const & type) :type(type)
{
    // std::cout << "AMateria Constructor was called" << std::endl;
}
AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor was called" << std::endl;
}
AMateria::AMateria(const AMateria& otherClass)
{
    *this = otherClass;
    // this->type = otherClass.type;
}
AMateria& AMateria::operator=(const AMateria& otherClass)
{
    if (this != &otherClass)
        return *this;
    return *this;
}
std::string const & AMateria::getType() const
{
    return this->type;
}
void AMateria::use(ICharacter& target)
{
    (void)target;
}