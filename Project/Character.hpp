#pragma once

#include "ICharacter.hpp"
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>

#define CLR "\033[0m"
#define BOLD "\033[1m"
#define ITAL "\033[3m"
#define UNDL "\033[4m"
#define DUNDL "\033[21m"
#define STRK "\033[9m"
#define BLNK "\033[5m"

#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YLW "\033[0;33m"
#define BLU "\033[0;34m"
#define PRP "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

#define RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"

class AMateria;

class Character : public ICharacter
{
	public:
		Character(std::string name);
		~Character();
		Character &operator=(const Character &obj);
		Character(const Character &copy);

		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void act(std::vector<ICharacter*>& characters);
		void attack(std::vector<ICharacter*> &characters);
		void defense(void);
		void skills(std::vector<ICharacter*> &characters);
		void magic(std::vector<ICharacter*> &characters);

		void setHealth(int health);
		void setAttackDamage(int ad);
		void setAttackPower(int ap);
		void setDefenseMagic(int dm);
		void setDefensePhysical(int dp);
		void setSpeed(int speed);
		void setAct(int act);
		void setDef(int def);
		void setMana(int mana);
		void setMaxHealth(int maxHealth);
		void setBaseSpeed(int speed);
		void setEffect(int index, const std::string& effect);
		void setTurn(int index, int turn);
		void setBuff(std::string buff, int turn);
		void setStab(std::string stab);
		void setStatus(bool status);
		
		int getHealth(void) const;
		int getAttackDamage(void) const;
		int getAttackPower(void) const;
		int getDefensemagic(void) const;
		int getDefensePhysical(void) const;
		int getSpeed(void) const;
		int getAct(void) const;
		int getDef(void) const;
		int getMana(void) const;
		int getMaxHealth(void) const;
		int getBaseSpeed(void) const;
		stats getStats(int index) const;
		buffs getBuff() const;
		std::string getStab() const;
		bool getStatus() const;

	private:
		Character();

		std::string _name;
		AMateria *_inventory[16];

		int _maxHealth;
		int _health;
		int _mana;
		int _attackDamage;
		int _attackPower;
		int _defenseMagic;
		int _DefensePhysical;
		int _speed;
		int _baseSpeed;
		bool _act;
		bool _isDef;
		bool _fireStab;
		bool _iceStab;
		bool _lightningStab;
		bool _windStab;


		stats 	_statsturn[4];
		buffs 	_status;
		bool	_hasStatus;
};
