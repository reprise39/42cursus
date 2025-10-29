/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:48:11 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/29 09:05:22 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//structor
template<typename T>
Array<T>::Array() : _slotptr(NULL), _size(0)
{
	std::cout << blue << "Defo-"
		<< ScalarConverter::strMyClass() << strConstMsg() << reset << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _slotptr(new T[n]), _size(n)
{
	std::cout << blue << "uInt-"
		<< ScalarConverter::strMyClass() << strConstMsg() << reset << std::endl;	
}

template<typename T>
Array<T>::Array(const Array& cp)
{
	*this = cp;

	std::cout << blue << "Copy-"
		<< ScalarConverter::strMyClass() << strConstMsg() << reset << std::endl;	
}

template<typename T>
Array<T>::~Array()
{
	delete[] (this->_slotptr);

	std::cout << red << "Defo-"
		<< ScalarConverter::strMyClass() << strDestMsg() << reset << std::endl;
}

//function

template<typename T>
size_t Array<T>::getSize()
{
	return (this->_size);
}

//operatir
template<typename T>
Array<T>& Array<T>operator=(const Array& other)
{
	
}