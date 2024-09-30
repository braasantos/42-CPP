#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( std::string type );
        ~Ice();
        Ice( const Ice& otherClass );
        Ice& operator=( const Ice& otherClass );
        AMateria* clone( void ) const;
        void use(ICharacter& target);
};