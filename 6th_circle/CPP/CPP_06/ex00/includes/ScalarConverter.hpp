/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:44:11 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/25 09:17:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

//include inb
# include "sio.hpp"

#include <climits>
#include <limits>

#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <iomanip>

//def macro

//def myClass
class ScalarConverter
{
	private:
		// for be canonical
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);

	public:
		// the subject
		static int convert(std::string str);

		// for print
		static const std::string strMyClass();

};

#endif
