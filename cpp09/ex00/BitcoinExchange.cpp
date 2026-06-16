#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{

}

Bitcoin::~Bitcoin()
{

}

Bitcoin Bitcoin::operator=(const Bitcoin &obj)
{
	this->data = obj.data;
	this->input = obj.input;
	return (*this);
}

Bitcoin::Bitcoin(const Bitcoin &copy)
{
	*this = copy;
}

bool isstringdigit(std::string str)
{
	for (unsigned long i = 0; i < str.substr(0, str.find("-")).length(); i++)
	{
		if (str.c_str()[i] < 48 || str.c_str()[i] > 57)
			return (0);
	}
	return (1);
}

std::list<std::pair<std::string, std::string> > Bitcoin::getInput()
{
	return (this->input);
}

std::list<std::pair<std::string, std::string> > Bitcoin::getData()
{
	return (this->data);
}

bool is_valid_date(std::string date)
{
	int month = atoi(date.substr(date.find("-") + 1, date.find("-", date.find("-") + 1)).c_str());
	int day = atoi(date.substr(date.rfind("-") + 1, std::string::npos).c_str());
	int year = atoi(date.substr(0, date.find("-")).c_str());
	
	if (!isstringdigit(date) || atoi(date.substr(0, date.find("-")).c_str()) < 2000 || atoi(date.substr(0, date.find("-")).c_str()) > 9999)
		return (0);
	if (day < 1 || day > 31)
		return (0);
	if (month < 1 || month > 12)
		return (0);
	if (month % 2 == 1 || month != 8)
	{
		if (day > 30)
			return (0);
	}
		if (month == 2)
	{
		int isLeapYear = 0;
		if (day > 29)
			return (0);
		if (year % 4 == 0 && year % 100 != 0)
			isLeapYear = 1;
		else if (year % 400 == 0)
			isLeapYear = 1;

		if (isLeapYear)
		{
			if (day == 29)
				return (1);	
		}
		else
		{
			if (day > 28)
				return (0);	
		}
	}
	return (1);
}

int	getOldest(std::list<std::pair<std::string, std::string > > data)
{
	int i = 0;
	int lowest = 99999999;
	std::string date;

	for (std::list<std::pair<std::string, std::string > >::iterator it = data.begin(); it != data.end(); ++it)
	{
		if (i == 0)
			it++;
		i++;
		if (it->first.length() > 6)
		{
			date = it->first;
			date.erase(4, 1);
			date.erase(6, 1);
		}
		if (lowest > atol(date.c_str()))
			lowest = atol(date.c_str());
	}
	return (lowest);
}

void Bitcoin::SearchDates()
{
	long Idata;
	long Ddata;
	long prevDate = 0;
	int i = 0;
	int j;
	int lowest = getOldest(data);
	std::string date;
	std::pair<std::string, std::string> Icopy;
	std::pair<std::string, std::string> Dcopy;

	for (std::list<std::pair<std::string, std::string > >::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (i == 0)
			it++;
		Icopy = *it;
		if (it->first.length() <= 6)
			it->second = "Invalid";
		else
		{
			it->first.erase(4, 1);
			it->first.erase(6, 1);
		}
		Idata = atol(it->first.c_str());
		i++;
		j = 0;
		for (std::list<std::pair<std::string, std::string > >::iterator it2 = data.begin(); it2 != data.end(); ++it2)
		{
			if (j == 0)
				it2++;
			if (it2->first.length() <= 6)
				it2->second = "Invalid";
			else
			{
				date = it2->first;
				date.erase(4, 1);
				date.erase(6, 1);	
			}
			Ddata = atol(date.c_str());
			if (Idata >= Ddata && it2->first != "")
			{
				prevDate = atof(it2->first.c_str());
				Dcopy = *it2;
			}
			j++;
		}
		if (it->second == "Invalid" || Dcopy.second == "Invalid" || atoi(it->first.c_str()) < lowest)
			std::cout << "Invalid Date or Value" << std::endl;
		else
			std::cout << Icopy.first << "=>" << it->second << " = " << atof(Dcopy.second.c_str()) * atof(it->second.c_str()) << std::endl;
	}
}

void Bitcoin::execInput()
{
	int i = 0;
	for (std::list<std::pair<std::string, std::string > >::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (it->first.length() == 8)
		{
			it->first.insert(7, "0");
		}
		else if (it->first.length() >= 8)
		{
			if (it->first.substr(it->first.rfind("-") + 1, std::string::npos).length() == 1)
				it->first.insert(8, "0");
			if (it->first.substr(it->first.find("-") + 1, it->first.find("-", it->first.find("-") + 1)).length() == 4)
				it->first.insert(5, "0");
		}
		if (i == 0)
			it++;
		i++;
		if (!is_valid_date(it->first))
			it->second = "Invalid";
		else if (atoi(it->second.c_str()) > 1000 || atoi(it->second.c_str()) < 0 || it->second.length() > 4)
			it->second = "Invalid";
	}
	this->SearchDates();
}


void Bitcoin::fillInput(char **args)
{
	std::string 	str;
	std::ifstream 	infile;
	std::ifstream 	infile2;
	int				pipeidx;
	int 			line = 0;

	infile.open(args[0]);
	if (infile.fail())
		throw std::invalid_argument ("bad file Descriptor");
	while(std::getline(infile, str))
	{
		pipeidx = str.find('|', 0);
		if (pipeidx == -1)
			this->input.push_back(make_pair(str, "Invalid"));
		else
			this->input.push_back(std::make_pair(str.substr(0, pipeidx), str.substr(pipeidx + 1, std::string::npos)));
		line++;
	}
	if (line < 2)
		throw std::invalid_argument ("bad file Descriptor");
	infile2.open(args[1]);
	if (infile2.fail())
		throw std::invalid_argument ("bad file Descriptor");
	while(std::getline(infile2, str))
	{
		pipeidx = str.find(',', 0);
		if (pipeidx == -1)
			this->data.push_back(make_pair(str, "Invalid"));
		else
			this->data.push_back(std::make_pair(str.substr(0, pipeidx), str.substr(pipeidx + 1, std::string::npos)));
	}
}