#include "Array.hpp"
#include "Array.tpp"
#include "string"

int main (void)
{
	Array<int> elem(3);
	Array<unsigned int> elem2;
	
	try
	{
		elem.setTab(0, 40);
		elem.setTab(1, '*');
		elem.setTab(2, -58);
		// elem2.setTab(0, 4);

		Array<int> copy(elem);

		std::cout << "elem size : " << elem.size() << std::endl;
		std::cout << "copy size : " << copy.size() << std::endl;
		std::cout << "elem2 size : " << elem2.size() << std::endl;

		for (int i = 0; i < 3; i++)
		{
			std::cout << "elem :" << elem[i] << std::endl;
			std::cout << "copy :" << copy[i] << std::endl;
			// std::cout << elem2[i] << std::endl;
		}

		copy.setTab(2, 21);

		std::cout << "copy :" << copy[2] << std::endl;
		std::cout << "elem :" << elem[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}