#pragma once

#include "string"
#include "iostream"
#include "vector"
#include "Character.hpp"

class ICharacter;

class AMateria
{

	private:
		AMateria();
	public:
		AMateria(std::string type);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &obj);
		AMateria (const AMateria &copy);

		void 	setType(std::string type);
		const std::string &getType() const;
		virtual AMateria *clone() const = 0;
		virtual int use(std::vector<ICharacter*> characters, int idx, ICharacter &caster) = 0;
	
	protected:
		std::string _type;
		std::string _name;
};