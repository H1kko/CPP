#include "FragTrap.hpp"

FragTrap::FragTrap()
{

	std::cout << "default constructor called for FragTrap" << std::endl;
	_name = "Nameless";
	_hp = 100;
	_maxhp = _hp;
	_end = 100;
	_ad = 30;
}

FragTrap::FragTrap(std::string name)
{

	std::cout << "constructor called for FragTrap" << std::endl;
	_name = name;
	_hp = 100;
	_maxhp = _hp;
	_end = 100;
	_ad = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "default destructor called for FragTrap" << std::endl;
}


FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout << "copy constructor called for FragTrap" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "copy assignment constructor called for FragTrap" << std::endl;
	setHp(obj.getHp(0));
	setEnd(obj.getEnd(0));
	setName(obj.getName());
	setAd(obj.getAd());
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " is asking for a high five !" << std::endl;
}