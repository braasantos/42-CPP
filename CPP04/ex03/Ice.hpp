#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
    protected:
        std::string type;
    public:
        Ice();
        Ice( std::string type );
        ~Ice();
        Ice( const Ice& otherClass );
        Ice& operator=( const Ice& otherClass );
        Ice& Clone( void );
        void use(ICharacter& target);
};