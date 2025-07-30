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
	std::cout << "MODE : DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchupburger. ";
	std::cout << "I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "MODE : INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "MODE : WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years, ";
	std::cout << "whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "MODE : ERROR" << std::endl;
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string str)
{
	std::string svec[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*hafunc[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for(long unsigned int i = 0 ; i < sizeof(svec)/sizeof(svec[0]) ; i++)
	{
		if(str == svec[i])
		{
			(this->*hafunc[i])();
			return ;
		}
	}
	return ;
}

static int check_argc(int argc)
{
	if(argc != 2)
	{
		std::cout << "error : need 1 argument that indicate <level>" << std::endl;
		std::cout << "level is below" << std::endl;
		std::cout << "<DEBUG> , <INFO> , <WARNING> or <ERROR>" << std::endl;
		return (1);
	}
	return (0);
}

static int set_level(std::string str)
{
	int level = -1;
	std::string svec[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(long unsigned int i = 0 ; i < sizeof(svec)/sizeof(svec[0]) ; i++)
	{
		if(str == svec[i])
		{
			level = i;
		}
	}
	return (level);
}

int main(int argc, char **argv)
{
	if(check_argc(argc) != 0)
		return (1);

	std::string str(argv[1]);
	int level = set_level(str);

	Harl h;
	// fallthrough
	switch(level)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			h.complain("DEBUG");
			/* fall through */
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			h.complain("INFO");
			/* fall through */
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			h.complain("WARNING");
			/* fall through */
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			h.complain("ERROR");
			break;
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		default:
			std::cout << "[ !? ]" << std::endl;
			break;
	}
	return (0);
}

