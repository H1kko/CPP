#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
Ice::Ice() : AMateria ("ice")
{

}

Ice::~Ice()
{

}

Ice  &Ice::operator=(const Ice &obj)
{
	this->_type = obj._type;
	return (*this);
}

Ice::Ice(const Ice &copy) : AMateria (copy)
{
	*this = copy;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void	effect(std::vector<ICharacter*> characters, int idx)
{
	int rdm;
	int i = 0;
	rdm = rand() % 10;
	if (rdm == 0)
	{
		characters[idx]->setBaseSpeed(characters[idx]->getSpeed());
		characters[idx]->setSpeed(characters[idx]->getSpeed() * 0.75);
		while (characters[idx]->getStats(i)._turn > 0 && i < 4)
		{
			if (characters[idx]->getStats(i).effect == "slow")
			{
				characters[idx]->setTurn(i, 3);;
				std::cout << RGB(50,50,150) << "ennemy's speed malus duration increased !" << CLR << std::endl;
				return ;
			}
			i++;
		}
		if (characters[idx]->getStats(i)._turn > 0)
		{
			std::cout << "ennemy is already fully debuffed" << std::endl;
			return ;
		}
		characters[idx]->setEffect(i, "slow");
		characters[idx]->setTurn(i, 3);
		std::cout << RGB(50,50,150) << "ennemy speed decreased !" << CLR << std::endl;
	}
}

int Ice::use(std::vector<ICharacter*> characters, int idx, ICharacter &caster)
{
	int dmg;

	double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);
	dmg = caster.getAttackPower() / (1 + (characters[idx]->getDefensemagic() * 1.125 / 100));
	dmg *= 1.33;
	if (caster.getStab() == "ice")
		dmg *= 1.12;
	dmg *= rdm;
	std::cout << caster.getName() << " shoots an ice bolt at " << characters[idx]->getName() << " dealing " << dmg << " damages" << std::endl;
	characters[idx]->setHealth(characters[idx]->getHealth() - dmg);
	effect(characters, idx);
	caster.setMana(caster.getMana() - 25);
	
	return (0);
}