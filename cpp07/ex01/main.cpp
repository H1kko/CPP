#include "iter.hpp"
#include "iostream"
#include <ctype.h>

template <typename T, typename F> void iter(T *array, const int len, F func)
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

int tabadd(int &nb)
{
	nb += 1;
	return (nb);
}

double tabdouble(const double &nb)
{
	int n = nb;
	n *= 2;
	return (n);
}

int main (void)
{;

	int tab[] = {5, 1, 42, 38, 66, 69};
	double tab2[] = {1.9, 15.7, 42.42, 99.21};
	iter(tab, 6, tabadd);
	iter(tab2, 4, tabdouble);
	
	for (int i = 0; i < 6; i++)
		std::cout << tab[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << tab2[i] << std::endl;
}