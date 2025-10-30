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

	if(ft_isfinite(d) && std::numeric_limits<int>::min() <= d && std::numeric_limits<int>::max() >= d)
	{
		isinInt = true;
		i = static_cast<int>(d);
	}

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

	//float & double
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
}

//convert
static int getdoubleToPrint(std::string str)
{
	char* eptr;
	double d = strtod(str.c_str(), &eptr);
	if(*eptr == 'd' || *eptr == 'f')
		++eptr;
	if(*eptr == '\0')
	{
		printdouble(d);
		return (0);
	}
	else
	{
		std::cout << "convert error" << std::endl;
		return (1);
	}
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

	//float & double
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(l) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(l) << std::endl;
}

static int getlongToPrint(std::string str)
{
	char* eptr;
	long l = strtol(str.c_str(), &eptr,10);
	if(*eptr == 'i' || *eptr == 'l' || *eptr == 'f')
		++eptr;
	if(*eptr == '\0')
	{
		printlong(l);
		return (0);
	}
	else
	{
		std::cout << "convert error" << std::endl;
		return (1);
	}
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
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
			break;
		}
		case 2:case 3:case 4:case 5:
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "inf" << std::endl;
			std::cout << "double: " << "inff" << std::endl;
			break;
		}
		case 6:case 7:
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "-inf" << std::endl;
			std::cout << "double: " << "-inff" << std::endl;
			break;
		}
	}
}

int ScalarConverter::convert(std::string str)
{
	int ret = 0;

	if(str.length() == 1 && !isdigit(str[0]))
	{
		// char(using long)
		long l = static_cast<long>(str[0]);
		printlong(l);
		return (0);
	}
	if(isSpecial(str) == true)
	{
		// special
		printSpecial(str);
		return (0);
	}
	if(str.find('.') != std::string::npos)
	{
		// double or float
		ret = getdoubleToPrint(str);
		return (ret);
	}
	// int-long
	ret = getlongToPrint(str);
	return (ret);
}
