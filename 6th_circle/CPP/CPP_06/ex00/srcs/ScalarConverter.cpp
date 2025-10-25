/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:22:45 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/25 09:22:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// for canonical
ScalarConverter::ScalarConverter()
{
	std::cout << blue
		<< ScalarConverter::strMyClass() << strConstMsg() << reset << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;

	std::cout << blue
		<< ScalarConverter::strMyClass() << strConstMsg() << reset << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << red 
		<< ScalarConverter::strMyClass() << strDestMsg() << reset << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if(this != &other)
	{
		(void)other;
	}
	return (*this);
}

// for exception class
const std::string ScalarConverter::strMyClass()
{
	return ("<class : ScalarConverter> ");
}

void ScalarConverter::convert(std::string str)
{
	(void)str;
}

// const char* ScalarConverter::GradeTooHighException::what() const throw()
// {
// 	return ("Grade is too High");
// }

// const char* ScalarConverter::GradeTooLowException::what() const throw()
// {
// 	return ("Grade is too Low");
// }
