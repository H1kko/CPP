#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "SuperIce.hpp"
#include "Cure.hpp"
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// typedef ICharacter* character;
// typedef std::vector<character> characters;
// typedef characters::iterator characters_it;

bool turnOrderDefiner(const std::pair<double, ICharacter*>& a, const std::pair<double, ICharacter*>& b) {
    return a.first > b.first;
}


void	begin_turn(std::vector<ICharacter*> characters)
{
	std::vector< std::pair<double, ICharacter*> > turnOrder;

	for (std::vector<ICharacter*>::iterator it = characters.begin(); it != characters.end(); ++it)
	{
		ICharacter *ch = *it;
		double rdm = 0.85 + (static_cast<double>(rand()) / RAND_MAX) * 0.30;
    	double agi = ch->getSpeed() * rdm;
		ch->setDef(0);
		turnOrder.push_back(std::pair<double, ICharacter*>(agi, ch));
	}
	
	std::sort(turnOrder.begin(), turnOrder.end(), turnOrderDefiner);
	for (std::vector<std::pair<double, ICharacter*> >::iterator it = turnOrder.begin(); it != turnOrder.end(); ++it)
	{
		ICharacter *ch = it->second;
		if (ch->getHealth() > 0)
			ch->act(characters);
	}
}


int main ()
{
	srand(time(0));

	ICharacter *char1 = new Character("dps");
	ICharacter *char2 = new Character("tank");
	ICharacter *char3 = new Character("mage");
	ICharacter *char4 = new Character("heal");

	ICharacter *char5 = new Character("boss");

	char1->setHealth(360);
	char2->setHealth(400);
	char3->setHealth(275);
	char4->setHealth(310);

	char5->setHealth(5000);

// ============================
	
	char1->setAttackDamage(100);
	char2->setAttackDamage(125);
	char3->setAttackDamage(60);
	char4->setAttackDamage(75);

	char5->setAttackDamage(200);

// ============================
	
	char1->setMana(200);
	char2->setMana(50);
	char3->setMana(400);
	char4->setMana(300);

	char5->setMana(200000);

// ============================
	
	char1->setAttackPower(100);
	char2->setAttackPower(50);
	char3->setAttackPower(130);
	char4->setAttackPower(115);

	char5->setAttackPower(125);

// ============================

	char1->setSpeed(100);
	char2->setSpeed(85);
	char3->setSpeed(113);
	char4->setSpeed(108);

	char5->setSpeed(110);

// =============================

	char1->setDefensePhysical(50);
	char2->setDefensePhysical(70);
	char3->setDefensePhysical(25);
	char4->setDefensePhysical(37);

	char5->setDefensePhysical(63);

// ==============================

	char1->setDefenseMagic(50);
	char2->setDefenseMagic(30);
	char3->setDefenseMagic(70);
	char4->setDefenseMagic(60);

	char5->setDefenseMagic(63);

// ===============================
	std::vector<ICharacter*> characters;
	characters.push_back(char1);
	characters.push_back(char2);
	characters.push_back(char3);
	characters.push_back(char4);
	characters.push_back(char5);	

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	AMateria	*tmp = src->createMateria("ice");

	src->learnMateria(new Cure());
	AMateria	*tmp2 = src->createMateria("cure");

	src->learnMateria(new SuperIce());
	AMateria	*tmp3 = src->createMateria("superice");

	char1->equip(tmp);
	char2->equip(tmp);
	char3->equip(tmp);
	char4->equip(tmp);
	
	char1->equip(tmp2);
	char2->equip(tmp2);
	char3->equip(tmp2);
	char4->equip(tmp2);

	char1->equip(tmp3);
	char2->equip(tmp3);
	char3->equip(tmp3);
	char4->equip(tmp3);
	while (characters[4]->getHealth() > 0 || (characters[0]->getHealth() > 0 && characters[1]->getHealth() > 0 && characters[2]->getHealth() > 0 && characters[3]->getHealth() > 0))
	{
		system("clear");
		begin_turn(characters);
	}
	if (characters[4]->getHealth() == 0)
		std::cout << "You Win ! :)" << std::endl;










	
	
	// AMateria	*tmp4 = src->createMateria("cure");
	// AMateria	*tmp5 = src->createMateria("cure");

	delete char1;
	delete char2;
	delete char3;
	delete char4;
	delete char5;
	delete src;
	delete tmp;
	delete tmp2;
	// delete tmp3;
	// delete tmp4;
	// delete tmp5;
}