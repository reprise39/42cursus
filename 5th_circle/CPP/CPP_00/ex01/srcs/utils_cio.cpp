/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:25:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/10 14:25:59 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phonebook.hpp"

void cin_line_clear(void)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void cin_all_clear(void)
{
	std::cin.clear();
	while (std::cin.peek() != EOF && std::cin.peek() != '\n')
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string red(const std::string& text)
{
	return ("\033[31m" + text + "\033[0m");
}

std::string yellow(const std::string& text)
{
	return ("\033[33m" + text + "\033[0m");
}

std::string blue(const std::string& text)
{
	return ("\033[34m" + text + "\033[0m");
}