#pragma once

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
    protected:
        std::string type;
    public:
        Cure();
        Cure( std::string type );
        ~Cure();
        Cure( const Cure& otherClass );
        Cure& operator=( const Cure& otherClass );
        Cure& Clone( void );
        void use(ICharacter& target);
};