#include "ScavTrap.hpp"

int	main (void)
{
	ClapTrap clap1("Clap");
	ScavTrap clap2("Scav");

	clap1.attack(clap2.getName());
	clap2.attack(clap1.getName());
	clap1.attack(clap2.getName());

	clap1.getMp(1);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap2.getHp(1);

	clap1.getMp(1);

	clap2.beRepaired(1);
	clap2.getMp(1);

	clap2.attack(clap1.getName());
	clap2.attack(clap1.getName());
	clap2.guardGate();
	clap2.attack(clap1.getName());
	clap2.attack(clap1.getName());
	clap2.attack(clap1.getName());
}