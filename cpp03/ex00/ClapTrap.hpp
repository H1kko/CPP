#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &obj);
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void		setHp(int const hp);
		void		setAd(int const hp);
		void		setMp(int const hp);
		void		setName(std::string const name);
		int			getHp(bool display) const;
		int			getAd(void) const;
		int			getMp(bool display) const;
		std::string	getName(void) const;

	private:
		int		_hp;
		unsigned int		_maxhp;
		int		_ad;
		int 	_mp;
		std::string	_name;
};
#endif