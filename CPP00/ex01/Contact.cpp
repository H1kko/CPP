#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact successfully created" << std::endl;
	Contact::_exist = 0;
}

Contact::~Contact()
{
	std::cout << "Contact successfully destroyed" << std::endl;
}

std::string Contact::getFname()
{
	return (this->_firstname);
}
std::string Contact::getLname()
{
	return (this->_lastname);
}
std::string Contact::getNname()
{
	return (this->_nickname);
}
std::string Contact::getNumber()
{
	return (this->_number);
}
std::string Contact::getSecret()
{
	return (this->_secret);
}
bool	Contact::getExist(void)
{
	return (this->_exist);
}

void	Contact::setFirstName(std::string first_name)
{
	this->_firstname = first_name;
}

void	Contact::setLastName(std::string lastname)
{
	this->_lastname = lastname;
}

void	Contact::setNickName(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setNumber(std::string number)
{
	this->_number = number;
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

void	Contact::setExist(bool exist)
{
	this->_exist = exist;
}