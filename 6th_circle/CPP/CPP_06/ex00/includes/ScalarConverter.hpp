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

//def macro

//def myClass
class ScalarConverter
{
	public:
		// for be canonical
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);

		//
		void convert(std::string str);

		// for print
		const std::string strMyClass();

		// exception class
		// class GradeTooHighException : public std::exception
		// {
		// 	public:
		// 		const char* what() const throw();
		// };
	
		// class GradeTooLowException : public std::exception
		// {
		// 	public:
		// 		const char* what() const throw();
		// };
	
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& oput);

#endif
