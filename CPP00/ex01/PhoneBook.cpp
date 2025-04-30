/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:41:05 by maregnie          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:45 by maregnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	PhoneBook::index = 0;
	std::cout << "PhoneBook succesfully created !" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook succesfully destroyed !" << std::endl;
}

void PhoneBook::add(void)
{
	std::string	buf;
	buf = "";
	while (1)
	{
		if (PhoneBook::_contact[PhoneBook::index].getExist() == 1)
			{
				while (buf != "yes" || buf != "no")
				{
					std::cout << "You already have 8 contacts. Do you want to overwright the oldest ? yes / no" << std::endl;
					std::getline(std::cin, buf);
					if (buf == "yes")
					{
						std::cout << "Overwriting the first contact..." << std::endl;
						break ;
					}
					else if (buf == "no")
					{	
						std::cout << "aborting..." << std::endl;
						return ;
					}
					else
						std::cout << "Bad Input" << std::endl;
					
				}
			}
		std::cout << "Enter your contact's first name : ";
		std::getline(std::cin, buf);
		if (buf != "")
			PhoneBook::_contact[PhoneBook::index].setFirstName(buf);
		std::cout << "Enter your contact's last name : ";
		std::getline(std::cin, buf);
		if (buf != "")
			PhoneBook::_contact[PhoneBook::index].setLastName(buf);
		std::cout << "Enter your contact's nick name : ";
		std::getline(std::cin, buf);
		if (buf != "")
			PhoneBook::_contact[PhoneBook::index].setNickName(buf);
		std::cout << "Enter your contact's number : ";
		std::getline(std::cin, buf);
		if (buf != "")
			PhoneBook::_contact[PhoneBook::index].setNumber(buf);
		std::cout << "Enter your contact's darkest secret : ";
		std::getline(std::cin, buf);
		if (buf != "")
			PhoneBook::_contact[PhoneBook::index].setSecret(buf);
		PhoneBook::_contact[PhoneBook::index].setExist(1);
		PhoneBook::index = PhoneBook::index + 1;
		if (PhoneBook::index == 8)
			PhoneBook::index = 0;
		return ;
	}
}

void	PhoneBook::search(void)
{
	std::string	tmp;
	bool _bool = 0;

	for (int i = 0; i < 8; i++)
	{
		if (PhoneBook::_contact[0].getExist() == 0)
		{
			std::cout << "You don't have any registered contact" << std::endl;
			return ;
		}
		if (PhoneBook::_contact[i].getExist() == 1)
		{
			std::cout << "[" << i << "]       |";
			tmp = PhoneBook::_contact[i].getFname();
			if (tmp == "")
				tmp = "(empty)";
			tmp = tmp + "                ";
			for (int i = 10; tmp[i] != 0; i++)
			{	
				if (tmp[i] != ' ')
				{
					_bool = 1;
					break ;
				}
			}
			tmp.resize(10);
			if (tmp[9] != ' ' && _bool)
				tmp[9] = '.';
			std::cout << tmp << "|";
			tmp = PhoneBook::_contact[i].getLname();
			if (tmp == "")
				tmp = "(empty)";
			tmp = tmp + "               ";
			for (int i = 10; tmp[i] != 0; i++)
			{	
				if (tmp[i] != ' ')
				{
					_bool = 1;
					break ;
				}
			}
			tmp.resize(10);
			if (tmp[9] != ' ' && _bool)
				tmp[9] = '.';
			std::cout << tmp << "|";
			tmp = PhoneBook::_contact[i].getNname();
			if (tmp == "")
				tmp = "(empty)";
			tmp = tmp + "                ";
			for (int i = 10; tmp[i] != 0; i++)
			{	
				if (tmp[i] != ' ')
				{
					_bool = 1;
					break ;
				}
			}
			tmp.resize(10);
			if (tmp[9] != ' ' && _bool)
				tmp[9] = '.';
			std::cout << tmp;
			std::cout << std::endl;
		}
		else
			std::cout << "[" << i << "]       |          |          |" << std::endl;
	}
}