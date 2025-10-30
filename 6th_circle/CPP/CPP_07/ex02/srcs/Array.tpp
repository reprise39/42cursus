/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:48:11 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/30 11:55:09 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// structor
template <typename T>
Array<T>::Array() : _slotptr(NULL), _size(0)
{
	std::cout << blue
			  << strMyClass() << "Defo-" << strConstMsg() << reset << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _slotptr(new T[n]), _size(n)
{
	std::cout << blue
			  << strMyClass() << "uInt-" << strConstMsg() << reset << std::endl;
}

template <typename T>
Array<T>::Array(const Array &cp)
{
	*this = cp;

	std::cout << blue
			  << strMyClass() << "Copy-" << strConstMsg() << reset << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->_slotptr);

	std::cout << red
			  << strMyClass() << "Defo-" << strDestMsg() << reset << std::endl;
}

// function
template <typename T>
size_t Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const std::string Array<T>::strMyClass()
{
	return ("<class : Array> ");
}

// operatir
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		unsigned int new_size = other.size();

		delete[] (this->_slotptr);
		this->_slotptr = new T[new_size];
		this->_size = new_size;

		for (unsigned int i = 0; i < new_size; i++)
			this->_slotptr[i] = other[i];
	}
	return (*this);
}

template<typename T>
const T& Array<T>::operator[](size_t st)const
{
	if(st >= this->size())
		throw(Array<T>::ooa_exception());
	return (this->_slotptr[st]);
}

template <typename T>
T& Array<T>::operator[](size_t st)
{
	if(st >= this->size())
		throw(Array<T>::ooa_exception());
	return (this->_slotptr[st]);
}

//exception
template<typename T>
const char* Array<T>::ooa_exception::what() const throw()
{
	return ("Error : Out of Area Access");
}
