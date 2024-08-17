#pragma once

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& otherClass);
        MateriaSource& operator=(const MateriaSource& otherClass);
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};
