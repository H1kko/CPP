#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap clap1("clap1");
	ClapTrap clap2("clap2");

	clap1.attack(clap2.getName());
	clap2.attack(clap1.getName());
	clap1.attack(clap2.getName());

	clap1.getEnd(1);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap2.takeDamage(clap1.getAd());
	clap2.getHp(1);

	clap1.getEnd(1);

	clap2.beRepaired(1);
	clap2.getEnd(1);
	clap2.getHp(1);
	clap1.getHp(1);

	std::cout << "=======  MORT =======" << std::endl;
	
	clap2.takeDamage(99999999);
	clap1.attack(clap2.getName());
	clap2.attack(clap1.getName());
	clap1.attack(clap2.getName());

	clap1.getEnd(1);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAd());
	clap2.takeDamage(clap1.getAd());
	clap2.getHp(1);

	clap1.getEnd(1);

	clap2.beRepaired(1);
	clap2.getEnd(1);
	clap2.getHp(1);
	clap1.getHp(1);

}