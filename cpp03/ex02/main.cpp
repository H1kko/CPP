#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main (void)
{
	std::cout << "test contructeur";
	{
		ClapTrap clap1("Clap");
		ScavTrap Scav1("Scav");
		FragTrap Frag("Frag");

		clap1.attack(Scav1.getName());
		Scav1.attack(clap1.getName());
		clap1.attack(Scav1.getName());

		clap1.getEnd(1);

		Frag.highFivesGuys();
		Frag.attack(clap1.getName());
		clap1.takeDamage(Frag.getAd());
		Frag.attack(clap1.getName());
		clap1.takeDamage(Frag.getAd());
		Frag.attack(Scav1.getName());
		Scav1.takeDamage(Frag.getAd());

		Scav1.getHp(1);
		clap1.getHp(1);
		Frag.getHp(1);

		clap1.getEnd(1);
		clap1.setHp(1);
		clap1.beRepaired(30);
		clap1.getHp(1);
		Scav1.getEnd(1);

		std::cout << "===========  MORT  ===============" << std::endl;

		clap1.takeDamage(999999);

		clap1.attack(Scav1.getName());
		Scav1.attack(clap1.getName());
		clap1.attack(Scav1.getName());

		clap1.getEnd(1);

		Frag.highFivesGuys();
		Frag.attack(clap1.getName());
		clap1.takeDamage(Frag.getAd());
		Frag.attack(clap1.getName());
		clap1.takeDamage(Frag.getAd());
		Frag.attack(Scav1.getName());
		Scav1.takeDamage(Frag.getAd());

		Scav1.getHp(1);
		clap1.getHp(1);
		Frag.getHp(1);

		clap1.getEnd(1);
		clap1.setHp(1);
		clap1.beRepaired(30);
		clap1.getHp(1);
		Scav1.getEnd(1);
	}
	
}