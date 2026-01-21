/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:51:55 by maregnie          #+#    #+#             */
/*   Updated: 2025/05/09 14:31:33 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);

int main (void)
{
	Zombie *test;

	test = NULL;
	randomChump("trololol");
	randomChump("xdddd");
	test = test->newZombie("gerard");
	test->announce();
	delete(test);
}