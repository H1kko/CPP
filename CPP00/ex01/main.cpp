/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:15:44 by maregnie          #+#    #+#             */
/*   Updated: 2025/04/29 17:59:18 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook PhoneBook;
	std::string buf;
	while (std::getline(std::cin, buf))
	{
		if (buf == "EXIT")
			break ;
		else if (buf == "ADD")
			PhoneBook.add();
		else if (buf == "SEARCH")
			PhoneBook.search();
		else
			std::cout << "Bad Input." << std::endl;
	}
}