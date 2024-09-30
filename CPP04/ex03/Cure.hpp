#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure( std::string type );
        ~Cure();
        Cure( const Cure& otherClass );
        Cure& operator=( const Cure& otherClass );
        AMateria* clone( void ) const;
        void use(ICharacter& target);
};