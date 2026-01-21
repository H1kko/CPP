#include "easyfind.hpp"
#include "easyfind.tpp"
#include <vector>
#include "iostream"

int main (void)
{
	std::vector <int> array;
	array.push_back(5);
	array.push_back(8);
	array.push_back(8);
	array.push_back(10);
	array.push_back(21);
	array.push_back(42);
	array.push_back(-72);
	array.push_back(0);
	array.push_back(2147483647);
	try
	{
		int ret = easyfind(array, 2147483647);
		std::cout << ret << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}