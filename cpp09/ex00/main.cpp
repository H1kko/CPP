#include "BitcoinExchange.hpp"


int main (int argc, char** argv)
{
	
	if (argc < 2)
	{
		std::cout << "Expected arguments : Input, Data" << std::endl;
		return (1);
	}
	try
	{
		Bitcoin btc;
		btc.fillInput(&argv[1]);
		btc.execInput();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}