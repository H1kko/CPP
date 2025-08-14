#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{

	std::cout << "default constructor called for ScavTrap" << std::endl;
	_hp = 100;
	_maxhp = _hp;
	_mp = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(std::string name)
{

	std::cout << "constructor called for ScavTrap" << std::endl;
	_name = name;
	_hp = 100;
	_maxhp = _hp;
	_mp = 50;
	_ad = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "default destructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "copy constructor called for ScavTrap" << std::endl;
	setHp(copy.getHp(0));
	setMp(copy.getMp(0));
	setAd(copy.getAd());
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_mp <= 0 || this->_hp <= 0)
	{
		std::cout << "ScavTrap does not have enough ressources to perform this action" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->_mp--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " enters gate keeper mode !" << std::endl;
}