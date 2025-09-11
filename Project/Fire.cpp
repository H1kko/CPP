#include "Fire.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
Fire::Fire() : AMateria ("fire")
{

}

Fire::~Fire()
{

}

Fire  &Fire::operator=(const Fire &obj)
{
	this->_type = obj._type;
	return (*this);
}

Fire::Fire(const Fire &copy) : AMateria (copy)
{
	*this = copy;
}

AMateria *Fire::clone() const
{
	return (new Fire());
}

void	fireeffect(std::vector<ICharacter*> characters, int idx)
{
	int rdm;
	rdm = rand() % 10;
	if (rdm == 0)
	{
		if (characters[idx]->getStatus())
			return ;
		characters[idx]->setBuff("fire", 3);
		std::cout << RGB(0,0,180) << "ennemy is burning" << CLR << std::endl;
	}
}

int Fire::use(std::vector<ICharacter*> characters, int idx, ICharacter &caster)
{
	int dmg;
	double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);
	dmg = caster.getAttackPower() / (1 + (characters[idx]->getDefensemagic() * 1.125 / 100));
	dmg *= 1.33;
	if (caster.getStab() == "fire")
		dmg *= 1.12;
	dmg *= rdm;
	std::cout << caster.getName() << " shoots a fireball at " << characters[idx]->getName() << " dealing " << dmg << " damages" << std::endl;
	characters[idx]->setHealth(characters[idx]->getHealth() - dmg);
	fireeffect(characters, idx);
	caster.setMana(caster.getMana() - 25);

	return (0);
}