#include "Span.hpp"


int main (void)
{
	Span vector(10);
	srand(time(0));
	// vector.addNumber(42);
	// vector.addNumber(-42);
	// vector.addNumber(0);
	// vector.addNumber(10);
	vector.fillVector();
	
	// vector.fillVector();

	// vector.longestSpan();
	vector.shortestSpan();
}