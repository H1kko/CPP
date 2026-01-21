#include "Span.hpp"
#include "limits.h"
#include "algorithm"

Span::Span()
{
	N = 0;
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::~Span()
{
	
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	if (this == &obj)
		return (*this);
	this->N = obj.N;
	this->container = obj.container;
	return (*this);
}

std::vector<int> Span::getContainer()
{
	return(container);
}

void 	Span::fillVector()
{
	for (unsigned int i = 0; i < N; i++)
	{
		if (container.size() >= N)
			throw std::out_of_range("Container is already full");
		container.push_back(rand() % 1001);
	}
}

void	Span::addNumber(int number)
{
	if (container.size() >= N)
			throw std::out_of_range("Container is already full");
	container.push_back(number);
}

unsigned int Span::longestSpan()
{
	int max = INT_MIN;
	int min = INT_MAX;
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << std::endl << std::endl;
		if (max < *it)
			max = *it;
		if (min > *it)
			min = *it;
		
	}
	std::cout << "min = " << min << std::endl << "max = " << max << std::endl << "Longest span = " << max - min << std::endl;
	return ((unsigned int)max - min);
}

unsigned int Span::shortestSpan()
{
	Span copy = *this;
	unsigned int tmp = this->longestSpan();
	std::sort(copy.container.begin(), copy.container.end());
	for (std::vector<int>::iterator it = copy.container.begin(); it + 1 != copy.container.end(); it++)
	{
		if (tmp > (unsigned int)(*(it + 1) - *it))
			tmp = *(it + 1) - *it;
	}
	std::cout << "shortest span = " << tmp << std::endl;
	return(tmp);
}