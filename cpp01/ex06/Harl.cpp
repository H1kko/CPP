#include "Harl.hpp"
#include <iostream>
Harl::Harl()
{

}

Harl::~Harl()
{
	
}

void 	Harl::complain(std::string level)
{
	int i = 0;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		while (i <= 3)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			this->debug();
			break ;
		case 1:
			this->info();
			break ;
		case 2:
			this->warning();
			break ;
		case 3:
			this->error();
			break ;
		default:
			std::cout << "don't trick me bozo" << std::endl;
			break ;
	}
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << " think I deserve to have some extra bacon for free. I'e been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}