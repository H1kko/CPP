#pragma once
#include "iostream"

template <typename T>

class Array
{
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &original);
		Array operator=(const Array &original);
		
		T &operator[](unsigned int index);
		void	setTab(unsigned int index, T val);
		int size();

	private:
		T *tab;
		unsigned int tabsize;
};