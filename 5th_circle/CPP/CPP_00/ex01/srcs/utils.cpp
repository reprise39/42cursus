/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:05:20 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/10 19:05:20 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phonebook.hpp"

bool str_is_space(std::string str)
{
	for(size_t i = 0 ; i < str.length() ; i++)
	{
		if(std::isspace(str[i]) == false)
			return (false);
	}
	return (true);
}

int str_to_int(const std::string str, bool* success = NULL)
{
	std::istringstream iss(str);
	int result;

	iss >> result;
	if (iss.fail() || !iss.eof()) {
		if (success) *success = false;
		return (0);
	}

	if (success) *success = true;
	return (result);
}

std::string int_to_str(int val)
{
	std::ostringstream oss;
	oss << val;
	return (oss.str());
}

void print_line(std::string str)
{
	std::cout << "|";
	if(str.length() < 10)
		std::cout << std::setw(10) << std::right << str;
	else
	{
		for (int i = 0 ; i < 9 ; i++)
		{
			std::cout << str[i];
		}
		std::cout << '.';
	}
}

std::string get_str(std::string print_word)
{
	std::string input;
	while(1)
	{
		std::cout << "   " << std::right << "prease type : " << print_word << " : ";
		std::getline(std::cin,input);
		if(str_is_space(input) == false)
			return (input);
		else
			std::cout << red("      ! blank_inpt is forbidden !") << std::endl;
	}
}
