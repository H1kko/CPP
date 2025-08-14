#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{

	std::cout << "default constructor called for ClapTrap" << std::endl;
	_hp = 10;
	_maxhp = _hp;
	_mp = 10;
	_ad = 0;
}

ClapTrap::ClapTrap(std::string name)
{

	std::cout << "constructor called for ClapTrap" << std::endl;
	_name = name;
	_hp = 10;
	_maxhp = _hp;
	_mp = 10;
	_ad = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "default destructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "copy constructor called for ClapTrap" << std::endl;
	setHp(copy.getHp(0));
	setMp(copy.getMp(0));
	setAd(copy.getAd());
}


int		ClapTrap::getMp(bool display) const
{
	if (display)
		std::cout << this->getName() << " has " << _mp << " Mp left" << std::endl;
	return (_mp);
}

void	ClapTrap::setMp(int const mp)
{
	_mp = mp;
}



int		ClapTrap::getAd(void) const
{
	return (_ad);
}

void	ClapTrap::setAd(int const ad)
{
	_ad = ad;
}



void	ClapTrap::setHp(int const hp)
{
	_hp = hp;
}

int		ClapTrap::getHp(bool display) const
{
	if (display)
		std::cout << this->getName() << " has " << _hp << " Hp left" << std::endl;
	return (_hp);
}



void	ClapTrap::setName(std::string const name)
{
	_name = name;
}


std::string	ClapTrap::getName(void) const
{
	return (_name);
}



void	ClapTrap::attack(const std::string &target)
{
	if (this->_mp <= 0 || this->_hp <= 0)
	{
		std::cout << "not enough ressources to perform this action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->_mp--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	if (_hp < 0)
		_hp = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_mp <= 0 || this->_hp <= 0)
	{
		std::cout << "not enough ressources to perform this action" << std::endl;
		return ;
	}
	if (amount + _hp > _maxhp)
	{
		_hp = _maxhp;
		std::cout << this->getName() << " heals himself " << _maxhp << " health points !" << std::endl;
	}
	else
	{
		std::cout << this->getName() << " heals himself " << _maxhp << " health points !" << std::endl;
		_hp += amount;
	}
	this->_mp--;
}