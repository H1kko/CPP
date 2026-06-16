#include "PmergeMe.hpp"

int parse_arg(char **str)
{
	int i = 1;
	int j;

	while (str[i])
	{
		if (atoi(str[i]) < 0)
			return (0);
		j = 0;
		while (str[i][j])
		{
			if (!isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	PmergeMe merge;
	if (argc < 2)
	{
		std::cout << "at least 1 argument is needed" << std::endl;
		return(0);
	}
	if (!parse_arg(argv))
	{
		std::cout << "Invalid Arguments" << std::endl;
		return(0);
	}
	merge.fill_containers(argv, argc);
	merge.appairs();

	return (0);
}