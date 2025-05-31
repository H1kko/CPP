/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:15:44 by maregnie          #+#    #+#             */
/*   Updated: 2025/05/02 17:03:28 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook PhoneBook;
	std::string buf;
	std::cout << "PhoneBook> ";
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
		std::cout << "PhoneBook> ";
	}
}