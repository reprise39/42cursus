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

bool ft_isfinite(double x)
{
	// NaN check
	if (x != x)
		return (false);
	//range
	return (x <= std::numeric_limits<double>::max() && x >= -std::numeric_limits<double>::max());
}

static void printdouble(double d)
{
	bool isinInt = false;
	int i = 0;
	std::cout << "printdouble: d = " << d << std::endl;
	if(ft_isfinite(d) && std::numeric_limits<int>::min() <= d && std::numeric_limits<int>::max() >= d)
	{
		isinInt = true;
		i = static_cast<int>(d);
	}

	if(isinInt == false)
		std::cout << "out of int" << std::endl;
	else
		std::cout << "in of int" << i << std::endl;

	//char
	if(isinInt && std::isprint(static_cast<unsigned char>(d)))
		std::cout << "char: " << static_cast<unsigned char>(d) << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;

	//int
	if(isinInt)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: " << "Non displayable" << std::endl;

	std::cout << "float:" << static_cast<float>(d) << std::endl;
	std::cout << "double:" << static_cast<double>(d) << std::endl;
}

//convert
static void getdoubleToPrint(std::string str)
{
	char* eptr;
	double d = strtod(str.c_str(), &eptr);
	if(*eptr == 'd' || *eptr == 'f')
		++eptr;
	if(*eptr == '\0')
		printdouble(d);
	else
		std::cout << "convert error" << std::endl;
}

static void printlong(long l)
{
	bool isinInt = false;
	if(std::numeric_limits<int>::min() <= l && std::numeric_limits<int>::max() >= l)
		isinInt = true;

	//char
	if(isinInt && std::isprint(static_cast<unsigned char>(l)))
		std::cout << "char: " << static_cast<char>(l) << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;

	//int
	if(isinInt)
		std::cout << "int: " << static_cast<int>(l) << std::endl;
	else
		std::cout << "int: " << "Non displayable" << std::endl;

	std::cout << "float:" << static_cast<float>(l) << std::endl;
	std::cout << "double:" << static_cast<double>(l) << std::endl;
}

static void getlongToPrint(std::string str)
{
	char* eptr;
	long l = strtol(str.c_str(), &eptr,10);
	if(*eptr == 'i' || *eptr == 'l' || *eptr == 'f')
		++eptr;
	if(*eptr == '\0')
		printlong(l);
	else
		std::cout << "convert error" << std::endl;
}

static bool isSpecial(std::string str)
{
	int channel = 100;
	static std::string specialWords[8] = {"nan","nanf","inf","+inf","inff","+inff","-inf","-inff"};
	for(int i = 0 ; i < 8 ; i++)
	{
		if(str == specialWords[i])
			channel = i;
	}
	if(channel == 100)
		return (false);
	return (true);
}

static void printSpecial(std::string str)
{
	int channel = 100;
	static std::string specialWords[8] = {"nan","nanf","inf","+inf","inff","+inff","-inf","-inff"};
	for(int i = 0 ; i < 8 ; i++)
	{
		if(str == specialWords[i])
			channel = i;
	}
	switch(channel)
	{
		case 0: case 1:
		{
			std::cout << "char: " << "imppossible" << std::endl;
			std::cout << "int: " << "imppossible" << std::endl;
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
			break;
		}
		case 2:case 3:case 4:case 5:
		{
			std::cout << "char: " << "imppossible" << std::endl;
			std::cout << "int: " << "imppossible" << std::endl;
			std::cout << "float: " << "inf" << std::endl;
			std::cout << "double: " << "inff" << std::endl;
			break;
		}
		case 6:case 7:
		{
			std::cout << "char: " << "imppossible" << std::endl;
			std::cout << "int: " << "imppossible" << std::endl;
			std::cout << "float: " << "-inf" << std::endl;
			std::cout << "double: " << "-inff" << std::endl;
			break;
		}
	}
}

void ScalarConverter::convert(std::string str)
{
	std::cout << "raw_data = " << str << std::endl;

	if(str.length() == 1 && !isdigit(str[0]))
	{
		// char
		long l = static_cast<long>(str[0]);
		printlong(l);
		return;
	}
	if(isSpecial(str) == true)
	{
		// special
		printSpecial(str);
		return;
	}
	if(str.find('.') != std::string::npos)
	{
		// double or float
		std::cout << "double" << std::endl;
		getdoubleToPrint(str);
		return;
	}
	// int-long
	getlongToPrint(str);
}
