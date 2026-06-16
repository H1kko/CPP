#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe operator=(const PmergeMe &obj);

		void				fill_containers(char **argv, int argc);
		void				appairs();
		void 				FordJohnson(std::vector<int> &vec);
		void 				FordJohnsondeque(std::deque<int> &vec);
		std::vector<int>	InsertOrder(int size);
		std::deque<int> 	InsertOrderdeque(int size);
		int 				jacobsthal(int n);
		
	private:
		std::vector<int> vec;
		std::deque<int> deq;
};