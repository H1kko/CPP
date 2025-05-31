#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

		std::string getName();
		void		setName(std::string name);
		Weapon		*getWeapon();
		void		setWeapon(Weapon &weapon);
		void		attack();
		
	private:
		std::string _name;
		Weapon *_weapon;
};
#endif