#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string getFname(void);
		std::string getLname(void);
		std::string getNname(void);
		std::string getNumber(void);
		std::string getSecret(void);
		bool		getExist(void);
		void		setFirstName(std::string firstname);
		void		setLastName(std::string lastname);
		void		setNickName(std::string nickname);
		void		setNumber(std::string number);
		void		setSecret(std::string secret);
		void		setExist(bool exist);

	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _number;
		std::string _secret;
		bool		_exist;
};

#endif