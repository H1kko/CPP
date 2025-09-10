#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria ("cure")
{

}

Cure::~Cure()
{

}

Cure  &Cure::operator=(const Cure &obj)
{
	this->_type = obj._type;
	return (*this);
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	*this = copy;
}


AMateria *Cure::clone() const
{
	return (new Cure);
}

int Cure::use(std::vector<ICharacter*> characters, int idx, ICharacter &caster)
{
	double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);
	int amount;
	if (caster.getName() == "heal")
		amount = caster.getAttackPower() * 0.8;
	else
		amount = caster.getAttackPower() * 0.55;
	amount *= rdm;
	std::cout << caster.getName() << " regenerate some of " << characters[idx]->getName() << " wounds " << amount << " Hp has been healed"<< std::endl;
	caster.setMana(caster.getMana() - 25);
	characters[idx]->setHealth(characters[idx]->getHealth() + amount);
	return (0);
}