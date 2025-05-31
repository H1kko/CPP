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
int main (void)
{
	Zombie ptdr;
	Zombie lool;
	Zombie *test;

	test = NULL;
	ptdr.randomChump("trololol");
	lool.randomChump("xdddd");
	test = test->newZombie("gerard");

	ptdr.announce();
	lool.announce();
	test->announce();
	delete(test);
}