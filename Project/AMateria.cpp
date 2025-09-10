#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

AMateria::AMateria(std::string type)
{
	_type = type;
}

AMateria::~AMateria()
{

}

AMateria  &AMateria::operator=(const AMateria &obj)
{
	this->_type = obj._type;
	return (*this);
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}


void	AMateria::setType(std::string type)
{
	_type = type;
}

const std::string	&AMateria::getType(void) const
{
	return(_type);
}