#pragma once
#include "AMateria.hpp"
#include <vector>

class SuperFlame : public AMateria
{
	
	public:
		SuperFlame();
		~SuperFlame();
		SuperFlame &operator=(const SuperFlame &obj);
		SuperFlame (const SuperFlame &copy);		

		void 	setType(std::string type);
		const std::string &getType() const;
		AMateria *clone() const;
		int use(std::vector<ICharacter*> characters, int idx, ICharacter &caster);

	private:
		std::string _type;
};