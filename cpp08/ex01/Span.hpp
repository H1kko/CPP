#pragma once
#include <vector>
#include <ctime>
#include <cmath>
#include <stdexcept>
#include <iostream>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &obj);
		Span &operator=(const Span &obj);


		unsigned int shortestSpan();
		unsigned int longestSpan();
		void	addNumber(int number);
		void 	fillVector();
		std::vector<int> getContainer();


	private:
		std::vector<int> container;
		unsigned int N;
};