#pragma once
#include "algorithm"
#include "stack"
#include "iterator"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &obj);
		MutantStack &operator=(const MutantStack &obj);
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		typedef typename std::stack<T>::container_type::const_iterator const iterator;
	private:	
};