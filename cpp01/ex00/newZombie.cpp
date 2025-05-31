/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:20:24 by maregnie          #+#    #+#             */
/*   Updated: 2025/05/09 14:00:59 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* Zombie::newZombie(std::string name)
{
	Zombie *zombie = new Zombie;
	zombie->setName(name);
	return (zombie);
}