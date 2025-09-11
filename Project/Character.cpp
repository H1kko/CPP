#include "Character.hpp"
#include "AMateria.hpp"
#include <stdlib.h>

Character::Character()
{
	_name = "nameless";
	for (int i = 0; i < 4; i++)
	{
    	this->_inventory[i] = NULL;
		_act = 0;
		_isDef = 0;
	}
}


Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
	{
    	this->_inventory[i] = NULL;
		_act = 0;
		_isDef = 0;
	}

	std::cout << name << " has been created" << std::endl;
}

Character::~Character()
{
	std::cout << getName() << " has been deleted" << std::endl;
}

Character &Character::operator=(const Character &obj)
{
	this->_name = obj._name;
	return (*this);
}

Character::Character(const Character &copy)
{
	*this = copy;
}



const std::string	&Character::getName(void) const
{
	return(_name);
}


void	Character::equip(AMateria* m)
{
	int	i = 0;
	if (!m)
	{
		std::cout << "an error occured, materia is null" << std::endl;
		return ;
	}
	while (this->_inventory[i] && i < 4)
		i++;
	if (this->_inventory[3] != NULL)
	{
		std::cout << _name << "'s inventory is full unequip an AMateria first." << std::endl;
		return ;
	}
	else
	{
		this->_inventory[i] = m;
		std::cout << getName() << " equiped an " << m->getType() << " materia" << std::endl;
	}
	
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Slot out of range, enter a value beetwin 0 and 3" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "This slot is already empty" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << getName() << " unequiped a Materia at slot " << idx << std::endl;
}
// ========================================

stats Character::getStats(int index) const
{
    if (index >= 0 && index < 4)
        return _statsturn[index];

    stats defaultStat;
    defaultStat.effect = _statsturn->effect;
    defaultStat._turn = _statsturn->_turn;
    return defaultStat;
}


// ========================================

buffs Character::getBuff() const
{
    buffs defaultBuff;
    defaultBuff.effect = _status.effect;
    defaultBuff._turn = _status._turn;
    return defaultBuff;
}

// =======================================

bool Character::getStatus() const
{
    return _hasStatus;
}

// =======================================

int	Character::getAttackDamage(void) const
{
	return(_attackDamage);
}

void	Character::setAttackDamage(int ad)
{
	_attackDamage = ad;
}

// =======================================

int	Character::getAttackPower(void) const
{
	return(_attackPower);
}

void	Character::setAttackPower(int ap)
{
	_attackPower = ap;
}

// ========================================


int	Character::getDefensemagic(void) const
{
	return(_defenseMagic);
}

void	Character::setDefenseMagic(int dm)
{
	_defenseMagic = dm;
}

// ==========================================

int	Character::getDefensePhysical(void) const
{
	return(_DefensePhysical);
}

void	Character::setDefensePhysical(int dp)
{
	_DefensePhysical = dp;
}


// =============================================


int	Character::getSpeed(void) const
{
	return(_speed);
}

void	Character::setSpeed(int speed)
{
	_speed = speed;
}

// ==============================================

int	Character::getBaseSpeed(void) const
{
	return(_baseSpeed);
}

void	Character::setBaseSpeed(int speed)
{
	_baseSpeed = speed;
}

// ==============================================

int	Character::getHealth(void) const
{
	return(_health);
}

void	Character::setHealth(int health)
{
	_health = health;
}

// ==============================================

int	Character::getMaxHealth(void) const
{
	return(_maxHealth);
}

void	Character::setMaxHealth(int health)
{
	_maxHealth = health;
}

// ==============================================

int	Character::getMana(void) const
{
	return(_mana);
}

void	Character::setMana(int mana)
{
	_mana = mana;
}
// ==============================================

int	Character::getAct(void) const
{
	return(_act);
}

void	Character::setAct(int act)
{
	_act = act;
}

// ==============================================

int	Character::getDef(void) const
{
	return(_isDef);
}
// ==============================================

void	Character::setDef(int def)
{
	_isDef = def;
}
// ==============================================

void Character::setEffect(int index, const std::string& effect)
{
    if (index >= 0 && index < 4)
        _statsturn[index].effect = effect;
}

void Character::setTurn(int index, int turn)
{
    if (index >= 0 && index < 4)
        _statsturn[index]._turn = turn;
}

// ==============================================

void Character::setBuff(std::string buff, int turn)
{
    _status.effect = buff;
	_status._turn = turn;
}
// ==============================================

void Character::setStatus(bool status)
{
    _hasStatus = status;
}

// ==============================================

void Character::setStab(std::string stab)
{
    if (stab == "fire")
		_fireStab = 1;
	else if (stab == "ice")
		_iceStab = 1;
	else if (stab == "lightning")
		_lightningStab = 1;
	else if (stab == "wind")
		_windStab = 1;
	else
		return ;
}

std::string Character::getStab() const
{
	if (_fireStab)
		return ("fire");
	if (_iceStab)
		return ("ice");
	if (_lightningStab)
		return ("lightning");
	if (_windStab)
		return ("wind");
	else
		return (NULL);
}

// ==============================================

void	removeEffect(ICharacter &character, std::string effect, int idx)
{
	if (effect == "slow")
	{
		character.setSpeed(character.getBaseSpeed());
		std::cout << RGB(50,50,150) << "ennemy recovered his speed !" << CLR << std::endl;
	}
	character.setEffect(idx, "NONE");
}

void	Character::act(std::vector<ICharacter*> & characters)
{
	std::string buf;
	std::cout << std::endl;
	if (this->getBuff().effect == "fire")
	{
		int dmg;
		double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);
		dmg = 80 / (1 + (this->getDefensemagic() * 1.08 / 100));
		dmg *= 1.33 *rdm;
		dmg *= rdm;
	}
	for (int i = 0; i < 4; i++)
	{
		
		if (this->getStats(i)._turn > 0 && this->getStats(i).effect != "NONE")
		{
			this->setTurn(i, this->getStats(i)._turn - 1);
			std::cout << RGB(255,0,0) << this->getStats(i)._turn << CLR << std::endl;
			if (this->getStats(i)._turn == 0)
				removeEffect(*this, this->getStats(i).effect, i);
		}
	}
	if (this->getName() == "boss")
	{
		if (characters[0]->getHealth() <= 0 && characters[1]->getHealth() <= 0 && characters[2]->getHealth() <= 0 && characters[3]->getHealth() <= 0)
		{
			std::cout << "You Lose ! :(" << std::endl;
			exit(1);
		}
		std::cout << RGB(255,0,0) << "boss is acting..." << CLR << std::endl;
		this->attack(characters);
		return ;
	}
	std::cout << this->getName() << " is acting" << std::endl << std::endl;

	std::cout << "[1] Attack			[2] Defense" << std::endl << std::endl << std::endl << "[3] Skills			[4] Magic" << std::endl;
	for (std::vector<ICharacter*>::iterator it = characters.begin(); it != characters.end(); ++it)
	{
		ICharacter *tmp = *it;
		std::cout << std::endl << tmp->getName() << ": Health:" << tmp->getHealth() << "          Mana:" << tmp->getMana() << "          effect status: None" << "          stats modif: ";
		for (int i = 0; i < 4; i++)
		{
			std::cout << tmp->getStats(i).effect << ": ";
			std::cout << tmp->getStats(i)._turn << ", ";
		}
		std::cout << std::endl;
	}
	std::getline(std::cin, buf);

	if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > 4)
	{
		std::cout << std::endl << "wrong entry, try again" << std::endl << std::endl;
		std::cout << this->getName() << " is acting" << std::endl << std::endl;
		std::cout << "[1] Attack			[2] Defense" << std::endl << std::endl << std::endl << "[3] Skills			[4] Magic" << std::endl;
		std::getline(std::cin, buf);
	}
	std::cout << std::endl;
	switch (buf.c_str()[0] - 48)
	{
		case 1:
			this->attack(characters);
			break;
		case 2:
			this->defense();
			break;
		case 3:
			this->skills(characters);
			break;
		case 4:
			this->magic(characters);
			break;
		default:
			std::cout << "DEBUG" << std::endl;
	}
}

void	Character::attack(std::vector<ICharacter*> & characters)
{
	int rdmTarget;
	double atk;
	double rdm = 0.85 * (0.9 + (static_cast<double>(rand()) / RAND_MAX) * 0.2);

	if (this->getName() == "boss")
	{
		rdmTarget = rand() % 5;
		while (rdmTarget == 4 || characters[rdmTarget]->getHealth() <= 0)
			rdmTarget = rand() % 5;
		std::cout << this->getName() << " is attacking " << characters[rdmTarget]->getName() << std::endl;
		atk = this->getAttackDamage() / (1 + (characters[rdmTarget]->getDefensePhysical() * 1.125 / 100));
		atk *= rdm;
		if (characters[rdmTarget]->getDef() == 1)
			atk /= 2;
		characters[rdmTarget]->setHealth(characters[rdmTarget]->getHealth() - (int)atk);
		if (characters[rdmTarget]->getHealth() < 0)
		{
			std::cout << characters[rdmTarget]->getName() << " Died !" << std::endl;
			characters[rdmTarget]->setHealth(0);
		}
		std::cout << characters[rdmTarget]->getName() << " took " << (int)atk << " point of damage. He has " << characters[rdmTarget]->getHealth() << " Hp left"<< std::endl << std::endl;
	}

	else
	{
		std::cout << this->getName() << " is attacking " << characters[4]->getName() << std::endl;
		atk = this->getAttackDamage() / (1 + (characters[4]->getDefensePhysical() * 1.125 / 100));
		atk = atk * rdm;
	
		characters[4]->setHealth(characters[4]->getHealth() - (int)atk);
		if (characters[4]->getHealth() < 0)
			characters[4]->setHealth(0);
		std::cout << characters[4]->getName() << " took " << (int)atk << " point of damage. He has " << characters[4]->getHealth() << " Hp left"<< std::endl << std::endl;
	}

}

void	Character::defense(void)
{
	std::cout << std::endl << this->getName() << " is defending" << std::endl << std::endl;
	this->_isDef = 1;
}

void	Character::skills(std::vector<ICharacter*> & characters)
{
	(void) characters;
}

void	Character::magic(std::vector<ICharacter*> &characters)
{
	(void) characters;
	std::string buf;
	std::string target;

	std::getline(std::cin, buf);
	if (!this->_inventory[atoi(buf.c_str())])
	{
		std::cout << this->getName() << " has nothing equipped at slot " << buf << std::endl;
		return ;
	}
	if (this->_inventory[atoi(buf.c_str())]->getType() == "cure")
	{
		std::cout << "chose your target " << std::endl << "0: " << characters[0]->getName() << std::endl << "1: " << characters[1]->getName() << std::endl << "2: " << characters[2]->getName() << std::endl << "3: " << characters[3]->getName() << std::endl;
		std::getline(std::cin, target);
		if (atoi(target.c_str()) > 3)
		{
			std::cout << "chose an entry between 1 and 4" << std::endl;
			return ;
		}
		this->_inventory[atoi(buf.c_str())]->use(characters, atoi(target.c_str()), *this);
		return ;
	}
	this->_inventory[atoi(buf.c_str())]->use(characters, 4, *this);
}