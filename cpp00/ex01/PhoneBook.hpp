#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void	add(void);
		void	search(void);
	private:
		Contact _contact[8];
		int		index;
};

#endif