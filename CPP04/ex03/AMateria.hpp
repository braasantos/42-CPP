#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria(const AMateria& otherClass);
        AMateria& operator=(const AMateria& otherClass);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
