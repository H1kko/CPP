#pragma once
#include "AMateria.hpp"
#include <vector>

class SuperIce : public AMateria
{
	
	public:
		SuperIce();
		~SuperIce();
		SuperIce &operator=(const SuperIce &obj);
		SuperIce (const SuperIce &copy);		

		void 	setType(std::string type);
		const std::string &getType() const;
		AMateria *clone() const;
		int use(std::vector<ICharacter*> characters, int idx, ICharacter &caster);

	private:
		std::string _type;
};