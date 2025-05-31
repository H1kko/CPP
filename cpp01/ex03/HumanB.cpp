#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL)
{
	setName(name);
}

HumanB::~HumanB()
{
	
}

void		HumanB::setName(std::string name)
{
	_name = name;
}
std::string HumanB::getName()
{
	return (this->_name);
}
Weapon	*HumanB::getWeapon()
{
	return (_weapon);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	std::string name = getName();
	Weapon *weapon = getWeapon();
	if (weapon)
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with empty hands" << std::endl;
	}