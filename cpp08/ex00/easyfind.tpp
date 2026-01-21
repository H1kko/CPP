#include "easyfind.hpp"
#include <algorithm>

template <typename T>
int easyfind(T container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::invalid_argument("Parameter not found");
	return (*it);
}