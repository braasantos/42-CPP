#pragma once 

#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _materia[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character& otherClass);
        Character& operator=(const Character& otherClass);
        virtual ~Character();
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        AMateria*				inventory_peek(int idx);
};