#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

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