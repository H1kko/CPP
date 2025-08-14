#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main (void)
{
	ClapTrap clap1("Clap");
	ScavTrap clap2("Frag");
	FragTrap clap3("Frag");

	clap1.attack(clap2.getName());
	clap2.attack(clap1.getName());
	clap1.attack(clap2.getName());

	clap1.getMp(1);

	clap3.highFivesGuys();
	clap3.attack(clap1.getName());
	clap1.takeDamage(clap3.getAd());
	clap3.attack(clap1.getName());
	clap1.takeDamage(clap3.getAd());
	clap3.attack(clap2.getName());
	clap2.takeDamage(clap3.getAd());

	clap2.getHp(1);
	clap1.getHp(1);
	clap3.getHp(1);

	clap1.getMp(1);
	clap1.setHp(1);
	clap1.beRepaired(30);
	clap1.getHp(1);
	clap2.getMp(1);
}