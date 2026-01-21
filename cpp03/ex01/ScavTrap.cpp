#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{

	std::cout << "default constructor called for ScavTrap" << std::endl;
	_hp = 100;
	_maxhp = _hp;
	_end = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(std::string name)
{

	std::cout << "constructor called for ScavTrap" << std::endl;
	_name = name;
	_hp = 100;
	_maxhp = _hp;
	_end = 50;
	_ad = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "default destructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;
	std::cout << "copy constructor called for ClapTrap" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "copy assignment constructor called for ClapTrap" << std::endl;
	setHp(obj.getHp(0));
	setEnd(obj.getEnd(0));
	setName(obj.getName());
	setAd(obj.getAd());
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_end <= 0 || this->_hp <= 0)
	{
		std::cout << "ScavTrap does not have enough ressources to perform this action" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->_end--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " enters gate keeper mode !" << std::endl;
}