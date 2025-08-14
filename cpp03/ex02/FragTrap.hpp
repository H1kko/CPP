#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const ClapTrap &obj);
		FragTrap(std::string name);
		~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif