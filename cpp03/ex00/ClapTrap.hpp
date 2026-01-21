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
		ClapTrap(const std::string &name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void				setHp(int const hp);
		void				setAd(int const hp);
		void				setEnd(int const hp);
		void				setName(std::string const &name);
		const int	&getHp(bool display) const;
		const unsigned int	&getAd(void) const;
		const unsigned int	&getEnd(bool display) const;
		std::string			getName(void) const;

	private:
		int		_hp;
		unsigned int		_maxhp;
		unsigned int		_ad;
		unsigned int 		_end;
		std::string	_name;
};
#endif