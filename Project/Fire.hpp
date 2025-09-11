#pragma once
#include "AMateria.hpp"
#include <vector>

class Fire : public AMateria
{
	
	public:
		Fire();
		~Fire();
		Fire &operator=(const Fire &obj);
		Fire (const Fire &copy);		

		void 	setType(std::string type);
		const std::string &getType() const;
		AMateria *clone() const;
		int use(std::vector<ICharacter*> characters, int idx, ICharacter &caster);

	private:
		std::string _type;
};