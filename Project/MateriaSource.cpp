#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_storage[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_storage[i])
		{
			std::cout << _storage[i]->getType() << " Materia has been deleted at slot " << i << std::endl;
			delete _storage[i];
		}
	}
}

MateriaSource  &MateriaSource::operator=(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
		this->_storage[i] = obj._storage[i];
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 16; i++)
	{
		if (this->_storage[i] != NULL && this->_storage[i]->getType() == type)
		{
			std::cout << type  << "Materia " << " was created." << std::endl;
			return (this->_storage[i]->clone());
		}
	}
	std::cout << "can't create this Materia" << std::endl;
	return (NULL);
}

void	MateriaSource::learnMateria(AMateria *src)
{
	for (int i = 0; i < 16; i++)
	{
		if (this->_storage[i] == NULL)
		{
			this->_storage[i] = src;
			std::cout << "Materia " << src->getType() << " has been learnt" << std::endl;
			return ;
		}
	}
	std::cout << "Materia " << src->getType() << " learning failed, all your slots are full" << std::endl;

}