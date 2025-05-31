/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:51:55 by maregnie          #+#    #+#             */
/*   Updated: 2025/05/09 15:22:21 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main (void)
{
	int N = 10;
	Zombie *zombie;
	zombie = NULL;
	zombie = zombie->zombieHorde(N, "pascal");
	
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete [] zombie;
}