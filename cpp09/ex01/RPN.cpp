#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{
	
}

void	RPN::exec_stack(std::string str)
{
	unsigned long i = 0;
	int tmp1;
	int tmp2;

	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] <= '9' && str[i] >= '0')
			stack.push(str[i] - 48);
		
		else if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && stack.size() > 1)
		{

			if (str[i] == '+')
			{
				tmp1 = stack.top();
				stack.pop();
				tmp2 = stack.top();
				stack.pop();
				stack.push(tmp1 + tmp2);
				std::cout << stack.top() << std::endl;
			}
			else if (str[i] == '-')
			{
				tmp1 = stack.top();
				stack.pop();
				tmp2 = stack.top();
				stack.pop();
				stack.push(tmp2 - tmp1);
				std::cout << stack.top() << std::endl;
			}
			else if (str[i] == '*')
			{
				tmp1 = stack.top();
				stack.pop();
				tmp2 = stack.top();
				stack.pop();
				stack.push(tmp2 * tmp1);
				std::cout << stack.top() << std::endl;
			}
			else if (str[i] == '/')
			{
				tmp1 = stack.top();
				stack.pop();
				tmp2 = stack.top();
				stack.pop();
				if (tmp1 == 0 || tmp2 == 0)
				{
					std::cout << "divinding by 0 is forbidden, aborting" << std::endl;
					return;
				}
				stack.push(tmp2 / tmp1);
				std::cout << stack.top() << std::endl;
			}
		}
		i++;
	}
}