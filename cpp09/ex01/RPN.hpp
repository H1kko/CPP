#pragma once
#include "stack"
#include "iostream"
#include "string"
#include "stdlib.h"

class RPN
{
	public:
		RPN();
		~RPN();

		void	fill_wholestack();
		void	exec_stack(std::string str);

	private:
		std::stack<int> stack;
		
		
};
