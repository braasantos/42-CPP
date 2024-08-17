#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    // protected:
    //     std::string type;
    public:
        Ice();
        Ice( std::string type );
        ~Ice();
        Ice( const Ice& otherClass );
        Ice& operator=( const Ice& otherClass );
        // std::string const & getType() const;
        AMateria* clone( void ) const;
        void use(ICharacter& target);
};