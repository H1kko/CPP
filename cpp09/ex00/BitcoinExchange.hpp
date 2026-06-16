#pragma once

#include "iostream"
#include "list"
#include <string>
#include "fstream"
#include <stdlib.h>

class Bitcoin
{
	public:
		Bitcoin();
		~Bitcoin();
		Bitcoin(const Bitcoin &cpy);
		Bitcoin operator=(const Bitcoin &obj);

		std::list<std::pair<std::string, std::string> > getInput();
		std::list<std::pair<std::string, std::string> >  getData();
		void fillInput(char **args);
		void execInput();
		void SearchDates();

	private:
		std::list<std::pair<std::string, std::string> > input;
		std::list<std::pair<std::string, std::string> > data;
};