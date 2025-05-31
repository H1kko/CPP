#ifndef Zombie_HPP
# define Zombie_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void		announce();
		void		setName(std::string name);
		std::string	getName();
		static Zombie* zombieHorde(int N, std::string name);

	private:
		std::string _name;
};




#endif