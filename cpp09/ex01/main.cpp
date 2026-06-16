#include "RPN.hpp"


int parse_argv(char *str)
{
	int i = 0;
	int j = 0;
	int ope = 0;
	int num = 0;

	while (str[j])
		j++;
	if (str[0] == ' ' || str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
		return (0);
	if (str[j - 1] != '+' && str[j - 1] != '-' && str[j - 1] != '*' && str[j - 1] != '/')
		return (0);
	while (str[i])
	{
		if (ope == 1 && num == 1)
			return (0);
		if (!str[i + 1] && str[i] == ' ')
			return (0);
		else if (str[i] == ' ' && str[i + 1] == ' ')
			return (0);		
		else if ((str[i] < '0' || str[i] > '9') && (str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-' && str[i] != ' '))
			return (0);
		else if ((str[i] <= '9' && str[i] >= '0') && (str[i + 1] <= '9' && str[i + 1] >= '0'))
			return (0);
		else if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i + 1] == '-') && (str[i] == '*' || str[i] == '/') && (str[i + 1] == '*' || str[i + 1] == '/'))
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			num++;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			ope++;

		i++;
	}
	if (num != ope + 1)
		return (0);
	return (1);
}

int main (int argc, char **argv)
{
	RPN stack;
	if (argc != 2)
	{
		std::cout << "Only 1 argument is accepted" << std::endl;
		return 0;
	}
	if (!parse_argv(argv[1]))
	{
		std::cout << "Invalid argument" << std::endl;
		return (0);
	}
	stack.exec_stack(argv[1]);
	// std::cout << str.substr(1).c_str() << std::endl;
	return (0);
}