/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:29:00 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/16 19:20:16 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}

static void print_arg_error(void)
{
	std::cout << red << "" << reset << std::endl;
}

static int check_argc(int argc)
{
	if(argc != 2)
	{
		std::cout << red << "error : need 1 argument that indicate <level>" << reset << std::endl;
		std::cout << "level is below" << std::endl;
		std::cout << "<DEBUG> , <INFO> , <WARNING> or <ERROR>" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if(check_argc(argc) != 0)
	{
		print_arg_error();
		return (1);
	}

	// std::string str(argv[1]);

	Harl h;
	h.set_level(argv[1]);

	// fallthrough
	switch(h.get_level())
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			h.complain("DEBUG");
			// fall through
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			h.complain("INFO");
			// fall through
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			h.complain("WARNING");
			// fall through
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			h.complain("ERROR");
			break;
		case 42:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		default:
			std::cout << "[ !? ]" << std::endl;
			break;
	}
	return (0);
}