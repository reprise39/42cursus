/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:30:57 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/28 22:30:57 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

// include
#include "sio.hpp"

//assert
#include <cassert>

// macro

// class
template <typename T>
class Array
{
	public:
		// structor
		Array();
		Array(unsigned int n);
		Array(const Array &cp);
		~Array();

		// function
		size_t getSize() const;
		const std::string strMyClass();

		// operatir
		Array &operator=(const Array &other);
		T operator[](size_t st)const;
		T& operator[](size_t st);

		//exception
		class ooa_exception : public std::exception
		{
			const char* what() const throw();
		};

	private:
		T *_slotptr;
		size_t _size;	

};

// std::ostream& operator<<(std::ostream& os, const Array& Array);
#include "../srcs/Array.tpp"

#endif