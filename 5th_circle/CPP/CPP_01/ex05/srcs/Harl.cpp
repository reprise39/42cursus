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

void Harl::debug()
{
	std::cout << "| LEVEL : DEBUG" << std::endl;
	std::cout << "| I love having extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-specialketchupburger.";
	std::cout << " I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "| LEVEL : INFO" << std::endl;
	std::cout << "| I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "| LEVEL : WARNING" << std::endl;
	std::cout << "| I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years,";
	std::cout << " whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "| LEVEL : ERROR" << std::endl;
	std::cout << "| This is unacceptable!";
	std::cout << " I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string str)
{
	std::string svec[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*hafunc_ptr[])() = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for(long unsigned int i = 0 ; i < sizeof(svec)/sizeof(svec[0]) ; i++)
	{
		if(str == svec[i])
		{
			(this->*hafunc_ptr[i])();
			return ;
		}
	}
	return ;
}

void Harl::formatprint(std::string str)
{
	std::cout << "↓----------- start -------------↓" << std::endl;
	std::cout << "||input = " << str << std::endl;
	std::cout << "|" << std::endl;
	this->complain(str);
	std::cout << "↑-----------  end  -------------↑" << std::endl;
	std::cout << std::endl;
}
