/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maregnie <maregnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:41:05 by maregnie          #+#    #+#             */
/*   Updated: 2025/05/07 14:08:01 by maregnie         ###   ########.fr       */
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
bool	is_empty(std::string str)
{
	size_t	j = 0;
	for(size_t i = 0; i < str.size() && i < 10; i++)
	{
		if (str[i] == ' ' || str[i] == '	')
			j++;
		else
			j = 0;
	}
	if (j >= 10 || j >= str.size())
		return (1);
	return (0);
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
		if (is_empty(buf) || buf == "")
		{
			std::cout << "fields can't be empty" << std::endl;
			return ;
		}
		PhoneBook::_contact[PhoneBook::index].setFirstName(buf);
		std::cout << "Enter your contact's last name : ";
		std::getline(std::cin, buf);
		if (is_empty(buf) || buf == "")
		{
			std::cout << "fields can't be empty" << std::endl;
			return ;
		}
		PhoneBook::_contact[PhoneBook::index].setLastName(buf);
		std::cout << "Enter your contact's nick name : ";
		std::getline(std::cin, buf);
		if (is_empty(buf) || buf == "")
		{
			std::cout << "fields can't be empty" << std::endl;
			return ;
		}
		PhoneBook::_contact[PhoneBook::index].setNickName(buf);
		std::cout << "Enter your contact's number : ";
		std::getline(std::cin, buf);
		if (is_empty(buf) || buf == "")
		{
			std::cout << "fields can't be empty" << std::endl;
			return ;
		}
		PhoneBook::_contact[PhoneBook::index].setNumber(buf);
		std::cout << "Enter your contact's darkest secret : ";
		std::getline(std::cin, buf);
		if (is_empty(buf) || buf == "")
		{
			std::cout << "fields can't be empty" << std::endl;
			return ;
		}
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
	bool 		_bool = 0;
	int 		i;

	if (PhoneBook::_contact[0].getExist() == 0)
	{
		std::cerr << "You don't have any registered contact" << std::endl;
		return ;
	}
	std::cout << "          | firstname|  lastname|  nickname"<< std::endl;
	std::cout << "          |__________|__________|__________"<< std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (PhoneBook::_contact[i].getExist() == 1)
		{
			std::cout << "       [" << i << "]|";
			tmp = PhoneBook::_contact[i].getFname();
			while (tmp.size() < 10)
				tmp = " " + tmp;
			if (tmp.size() > 10)
				_bool = 1;
			tmp.resize(10);
			if (_bool)
				tmp[9] = '.';
			_bool = 0;
			std::cout << tmp << "|";
			tmp = PhoneBook::_contact[i].getLname();
			while (tmp.size() < 10)
				tmp = " " + tmp;
			if (tmp.size() > 10)
				_bool = 1;
			tmp.resize(10);
			if (_bool)
				tmp[9] = '.';
			_bool = 0;
			std::cout << tmp << "|";
			tmp = PhoneBook::_contact[i].getNname();
			while (tmp.size() < 10)
				 tmp = " " + tmp;
			if (tmp.size() > 10)
				_bool = 1;
			tmp.resize(10);
			if (_bool)
				tmp[9] = '.';
			_bool = 0;
			std::cout << tmp;
			std::cout << std::endl;
		}
		else
			std::cout << "       [" << i << "]|          |          |" << std::endl;
		}
		std::cout << "Enter the contact's index : ";
		std::getline(std::cin, tmp);
		i = tmp[0] - 48;
		if (i < 0 || i > 7 || tmp.size() != 1)
		{
			std::cout << "Invalid Input." << std::endl;
			return ;
		}
		if (!PhoneBook::_contact[i].getExist())
			std::cout << "This contact does not exist" << std::endl;
		else
		{
			std::cout << "firstname : " << _contact[i].getFname() << std::endl;
			std::cout << "lastname : " << _contact[i].getLname() << std::endl;
			std::cout << "nickname : " << _contact[i].getNname() << std::endl;
			std::cout << "Number : " <<_contact[i].getNumber() << std::endl;
			std::cout << "Darkest secret : " << _contact[i].getSecret() << std::endl;
		}
}