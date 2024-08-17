#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& otherClass)
{
    for (int i = 0; i < 4; i++)
    {
        if (otherClass._materia[i] != NULL)
            this->_materia[i] = otherClass._materia[i]->clone();
        else
            this->_materia[i] = NULL;
    }
    // // std::cout << "MateriaSource copy constructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& otherClass)
{
    // // std::cout << "MateriaSource assignation operator" << std::endl;
    if (this == &otherClass)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete _materia[i];
		if (otherClass._materia[i])
			_materia[i] = otherClass._materia[i]->clone();
        else
            _materia[i] = NULL;
	}
	return *this;
}
MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL)
        {
            delete this->_materia[i];
            this->_materia[i] = NULL;
        }
    }
}
void MateriaSource::learnMateria(AMateria* m)
{
    // std::cout << "MateriaSource learnMateria" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = m;
            return ;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materia[i])
            break ;
        if (this->_materia[i] && this->_materia[i]->getType() == type)
            return _materia[i]->clone();
            // std::cout << "MateriaSource createMateria " << _materia[i]->getType() << std::endl;
    }
    return NULL;
}