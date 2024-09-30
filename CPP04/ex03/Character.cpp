#include "Character.hpp"

Character::Character() : _name("default")
{
    // std::cout << "Character constructor was called" << std::endl;
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}
Character::Character(std::string name) : _name(name)
{
    // std::cout << "Character constructor was called" << std::endl;
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}
Character::Character(const Character& otherClass) : _name(otherClass._name)
{
    // std::cout << "Character copy constructor was called" << std::endl;
    *this = otherClass;
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

Character::~Character()
{
    // std::cout << "Character destructor was called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] != NULL)
        {
            delete _materia[i];
            _materia[i] = NULL;
        }
            
    }
}
Character& Character::operator=(const Character& otherClass)
{
    // std::cout << "Character assignation operator was called" << std::endl;
    if (this == &otherClass)
        return *this;
    _name = otherClass._name;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i])
            delete this->_materia[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (!otherClass._materia[i])
            this->_materia[i] = otherClass._materia[i]->clone();
    }
    return *this;
}
std::string const & Character::getName() const
{
    return this->_name;
}
/// @brief      looks for the first empty slot in 
///             the inventory and places the Materia there. 
///             If the inventory is full, it does nothing.
/// @param m 
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materia[i] && m)
        {
            this->_materia[i] = m;
            return;
        }
    }
    return ;
}
/// @brief 
/// @param idx 
void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Index not valid" << std::endl;
        return ;
    }
    if (!this->_materia[idx])
    {
        std::cout << "No materia in this slot" << std::endl;
        return ;
    }
    else
        this->_materia[idx] = NULL;
    return ;
}
void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !this->_materia[idx])
    {
        std::cout << "Index not valid" << std::endl;
        return ;
    }
    else
        this->_materia[idx]->use(target);
}

AMateria* Character::inventory_peek(int idx)
{
	if(idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return NULL;
	}
	return _materia[idx];
}