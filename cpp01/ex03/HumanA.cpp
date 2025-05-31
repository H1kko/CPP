#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(&weapon)
{

}

HumanA::~HumanA()
{
	
}

void		HumanA::setName(std::string name)
{
	_name = name;
}
std::string HumanA::getName()
{
	return (this->_name);
}
Weapon	*HumanA::getWeapon()
{
	return (_weapon);
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanA::attack()
{
	std::string name = getName();
	Weapon *weapon = getWeapon();
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}