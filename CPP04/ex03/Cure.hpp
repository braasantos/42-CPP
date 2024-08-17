#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    // protected:
    //     std::string type;
    public:
        Cure();
        Cure( std::string type );
        ~Cure();
        Cure( const Cure& otherClass );
        Cure& operator=( const Cure& otherClass );
        // std::string const & getType() const;
        AMateria* clone( void ) const;
        void use(ICharacter& target);
};