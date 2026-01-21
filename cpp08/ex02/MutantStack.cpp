#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{

}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &obj)
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &obj)
{
	
}


template <typename T>
MutantStack<T>::iterator MutantStack<T>::begin()
{
	return(this->c);
}

template <typename T>
MutantStack<T>::iterator MutantStack<T>::end()
{
	return(this->c);
}