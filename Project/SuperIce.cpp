#include "SuperIce.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
SuperIce::SuperIce() : AMateria ("superice")
{

}

SuperIce::~SuperIce()
{

}

SuperIce  &SuperIce::operator=(const SuperIce &obj)
{
	this->_type = obj._type;
	return (*this);
}

SuperIce::SuperIce(const SuperIce &copy) : AMateria (copy)
{
	*this = copy;
}

AMateria *SuperIce::clone() const
{
	return (new SuperIce());
}

void	effect(std::vector<ICharacter*> characters, int idx);

int SuperIce::use(std::vector<ICharacter*> characters, int idx, ICharacter &caster)
{
	int dmg;

	double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);
	dmg = caster.getAttackPower() / (1 + (characters[idx]->getDefensemagic() * 1.125 / 100));
	dmg *= 1.8;
	if (caster.getStab() == "ice")
		dmg *= 1.12;
	dmg *= rdm;
	std::cout << caster.getName() << " Materialize ice spikes at " << characters[idx]->getName() << " dealing " << dmg << " damages" << std::endl;
	characters[idx]->setHealth(characters[idx]->getHealth() - dmg);
	effect(characters, idx);
	caster.setMana(caster.getMana() - 50);
	
	return (0);
}