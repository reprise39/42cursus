/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:34:14 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/11 14:34:14 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() const
{
	std::cout << "LEVEL : DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchupburger. ";
	std::cout << "I really do!" << std::endl
			  << std::endl;
}

void Harl::info() const
{
	std::cout << "LEVEL : INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl
			  << std::endl;
}

void Harl::warning() const
{
	std::cout << "LEVEL : WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years, ";
	std::cout << "whereas you started working here just last month." << std::endl
			  << std::endl;
}

void Harl::error() const
{
	std::cout << "LEVEL : ERROR" << std::endl;
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl
			  << std::endl;
}

void Harl::complain(std::string str) const
{
	std::string svec[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*hafunc[])() const = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	for (long unsigned int i = 0; i < sizeof(svec) / sizeof(svec[0]); i++)
	{
		if (str == svec[i])
		{
			(this->*hafunc[i])();
			return;
		}
	}
	return;
}

void Harl::set_level(std::string str)
{
	std::string svec[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (long unsigned int i = 0; i < sizeof(svec) / sizeof(svec[0]); i++)
	{
		if (str == svec[i])
		{
			this->level = i;
			return;
		}
	}
	this->level = 42;
	return;
}

int Harl::get_level() const
{
	return (this->level);
}
