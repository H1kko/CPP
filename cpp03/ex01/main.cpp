#include "ScavTrap.hpp"

int	main (void)
{
	ClapTrap clap1("Clap");
	ScavTrap scav1("Scav");

	clap1.attack(scav1.getName());
	scav1.attack(clap1.getName());
	clap1.attack(scav1.getName());

	clap1.getEnd(1);

	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.getHp(1);
	scav1.getHp(1);

	clap1.getEnd(1);

	scav1.beRepaired(1);
	scav1.getEnd(1);

	scav1.attack(clap1.getName());
	scav1.attack(clap1.getName());
	scav1.guardGate();
	scav1.attack(clap1.getName());
	scav1.attack(clap1.getName());
	scav1.attack(clap1.getName());

		std::cout << "=======  MORT =======" << std::endl;
	
	scav1.takeDamage(99999999);
	clap1.attack(scav1.getName());
	scav1.attack(clap1.getName());
	clap1.attack(scav1.getName());

	clap1.getEnd(1);

	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.attack(scav1.getName());
	scav1.takeDamage(clap1.getAd());
	clap1.getHp(1);
	scav1.getHp(1);

	clap1.getEnd(1);

	scav1.beRepaired(1);
	scav1.getEnd(1);

	scav1.attack(clap1.getName());
	scav1.attack(clap1.getName());
	scav1.guardGate();
	scav1.attack(clap1.getName());
	scav1.attack(clap1.getName());
	scav1.attack(clap1.getName());

	scav1.beRepaired(1);
	scav1.getEnd(1);
	scav1.getHp(1);
	clap1.getHp(1);
}