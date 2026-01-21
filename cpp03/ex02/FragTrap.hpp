#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &obj);
		FragTrap(std::string name);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif