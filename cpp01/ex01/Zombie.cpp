/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:03:40 by maregnie          #+#    #+#             */
/*   Updated: 2025/05/09 12:29:29 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << getName() << " has been destroyed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	Zombie::_name = name;
}

std::string	Zombie::getName()
{
	return (_name);
}

void	Zombie::announce(void)
{
	std::cout << Zombie::getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}