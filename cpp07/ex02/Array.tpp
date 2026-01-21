#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	this->tab = new T[0];
	tabsize = 0;
}

template <class T>
Array<T>::~Array()
{
	delete [] tab;
}

template <class T>
void	Array<T>::setTab(unsigned int index, T val)
{
	if (index >= tabsize)
		throw std::out_of_range("Index out of bounds");
	tab[index] = val;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	tab = new T[n];
	tabsize = n;
	for(unsigned int i = 0; i < n; i++)
		tab[i] = 0;
}

template<class T>
Array<T>::Array(const Array &original)
{
	tabsize = original.tabsize;
	tab = new T[tabsize];
	for (unsigned int i = 0; i < tabsize; i++)
		tab[i] = original.tab[i];
}

template<class T>
Array<T> Array<T>::operator=(const Array &original)
{
	*this = original;
	return (*this);
}

template <class T>
int Array<T>::size()
{
	return (tabsize);
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= tabsize)
		throw std::out_of_range("Index out of bounds");
	return (tab[index]);
}