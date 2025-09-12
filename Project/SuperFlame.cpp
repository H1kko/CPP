#include "SuperFlame.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
SuperFlame::SuperFlame() : AMateria ("superflame")
{

}

SuperFlame::~SuperFlame()
{

}

SuperFlame  &SuperFlame::operator=(const SuperFlame &obj)
{
	this->_type = obj._type;
	return (*this);
}

SuperFlame::SuperFlame(const SuperFlame &copy) : AMateria (copy)
{
	*this = copy;
}

AMateria *SuperFlame::clone() const
{
	return (new SuperFlame());
}

void	effect(std::vector<ICharacter*> characters, int idx);

int SuperFlame::use(std::vector<ICharacter*> characters, int idx, ICharacter &caster)
{
	int dmg;

	double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);
	dmg = caster.getAttackPower() / (1 + (characters[idx]->getDefensemagic() * 1.125 / 100));
	dmg *= 1.8;
	if (caster.getStab() == "Flame")
		dmg *= 1.12;
	dmg *= rdm;
	std::cout << caster.getName() << " Materialize Flame spikes at " << characters[idx]->getName() << " dealing " << dmg << " damages" << std::endl;
	characters[idx]->setHealth(characters[idx]->getHealth() - dmg);
	effect(characters, idx);
	caster.setMana(caster.getMana() - 50);
	
	return (0);
}