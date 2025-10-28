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
# define ARRAY_HPP

// include
# include <iostream>

// macro

// class
template<typename T>
class Array
{
	public:

		//structor
		Array();
		Array(unsigned int n);
		Array(const Array& cp);
		~Array();

		//function
		size_t getSize();

		//operatir
		Array& operator=(const Array& other);

		private:
			T _slot;
			size_t _size;
};

// std::ostream& operator<<(std::ostream& os, const Array& Array);

#endif