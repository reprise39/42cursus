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
