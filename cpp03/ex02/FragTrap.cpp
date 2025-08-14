#include "FragTrap.hpp"

FragTrap::FragTrap()
{

	std::cout << "default constructor called for FragTrap" << std::endl;
	_hp = 100;
	_maxhp = _hp;
	_mp = 100;
	_ad = 30;
}

FragTrap::FragTrap(std::string name)
{

	std::cout << "constructor called for FragTrap" << std::endl;
	_name = name;
	_hp = 100;
	_maxhp = _hp;
	_mp = 100;
	_ad = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "default destructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "copy constructor called for FragTrap" << std::endl;
	setHp(copy.getHp(0));
	setMp(copy.getMp(0));
	setAd(copy.getAd());
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_mp <= 0 || this->_hp <= 0)
	{
		std::cout << "FragTrap does not have enough ressources to perform this action" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->_mp--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " is asking for a high five !" << std::endl;
}