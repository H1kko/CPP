#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &obj);
		MateriaSource (const MateriaSource &copy);

		void 		learnMateria(AMateria*);
		AMateria* 	createMateria(std::string const & type);

	private:
		AMateria	*_storage[16];
};