#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure &operator=(const Cure &obj);
		Cure (const Cure &copy);

		void 	setType(std::string type);
		const std::string &getType() const;
		AMateria *clone() const;
		int use(std::vector<ICharacter*> characters, int idx, ICharacter &caster);

	private:
		std::string _type;
};