#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "default constructor called" << std::endl;
	_name = "Nameless";
	_hp = 10;
	_maxhp = _hp;
	_end = 10;
	_ad = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "constructor called" << std::endl;
	_name = name;
	_hp = 10;
	_maxhp = _hp;
	_end = 10;
	_ad = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "copy constructor called for ClapTrap" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "copy assignment constructor called for ClapTrap" << std::endl;
	setHp(obj.getHp(0));
	setEnd(obj.getEnd(0));
	setName(obj.getName());
	setAd(obj.getAd());
	return *this;
}


const unsigned int		&ClapTrap::getEnd(bool display) const
{
	if (display)
		std::cout << this->getName() << " has " << _end << " end left" << std::endl;
	return (_end);
}

void	ClapTrap::setEnd(int const end)
{
	_end = end;
}

const unsigned int		&ClapTrap::getAd(void) const
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

const int		&ClapTrap::getHp(bool display) const
{
	if (display)
		std::cout << this->getName() << " has " << _hp << " Hp left" << std::endl;
	return (_hp);
}



void	ClapTrap::setName(std::string const &name)
{
	_name = name;
}


std::string	ClapTrap::getName(void) const
{
	return (_name);
}



void	ClapTrap::attack(const std::string &target)
{
	if (this->_end <= 0 || this->_hp <= 0)
	{
		std::cout << "not enough ressources to perform this action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->_end--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	if (_hp < 0)
	_hp = 0;
	std::cout << "\e[1;31m Damage: " << amount << ", Hp lefts : " << _hp << "\e[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_end <= 0 || this->_hp <= 0)
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
	this->_end--;
}