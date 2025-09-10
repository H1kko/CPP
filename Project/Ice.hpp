#pragma once
#include "AMateria.hpp"
#include <vector>

class Ice : public AMateria
{
	
	public:
		Ice();
		~Ice();
		Ice &operator=(const Ice &obj);
		Ice (const Ice &copy);		

		void 	setType(std::string type);
		const std::string &getType() const;
		AMateria *clone() const;
		int use(std::vector<ICharacter*> characters, int idx, ICharacter &caster);

	private:
		std::string _type;
};