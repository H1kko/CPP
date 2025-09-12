#pragma once

#include <vector>
#include "string"

class AMateria;

typedef struct stats
{
    std::string effect;
    int _turn; 
} t_stats;

typedef struct buffs
{
    std::string effect;
    int _turn;
} t_buffs;


class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void	act(std::vector<ICharacter*> & characters) = 0;
		virtual void	attack(std::vector<ICharacter*> & characters) = 0;
		virtual void	defense(void) = 0;
		virtual void	skills(std::vector<ICharacter*> & characters) = 0;
		virtual void	magic(std::vector<ICharacter*> & characters) = 0;
		virtual void 	HasAnyBuff() = 0;


		virtual void setHealth(int health) = 0;
		virtual void setAttackDamage(int ad) = 0;
		virtual void setAttackPower(int ap) = 0;
		virtual void setDefenseMagic(int dm) = 0;
		virtual void setDefensePhysical(int dp) = 0;
		virtual void setSpeed(int speed) = 0;
		virtual void setAct(int speed) = 0;
		virtual void setDef(int def) = 0;
		virtual void setMana(int def) = 0;
		virtual void setMaxHealth(int mana) = 0;
		virtual void setBaseSpeed(int speed) = 0;
		virtual void setEffect(int index, const std::string& effect) = 0;
		virtual void setTurn(int index, int turn) = 0;
		virtual void setBuff(std::string buff, int turn) = 0;
		virtual void setStab(std::string stab) = 0;
		virtual void setStatus(bool status) = 0;

		virtual int	getHealth(void) const = 0;
		virtual int	getAttackDamage(void) const = 0;
		virtual int	getAttackPower(void) const = 0;
		virtual int	getDefensemagic(void) const = 0;
		virtual int	getDefensePhysical(void) const = 0;
		virtual int	getSpeed(void) const = 0;
		virtual int	getAct(void) const = 0;
		virtual int	getDef(void) const = 0;
		virtual int	getMana(void) const = 0;
		virtual int	getMaxHealth(void) const = 0;
		virtual int getBaseSpeed(void) const = 0;
		virtual stats getStats(int index) const = 0;
		virtual buffs getBuff() const = 0;
		virtual std::string getStab() const = 0;
		virtual bool getStatus() const = 0;

};