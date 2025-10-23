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

#include "Zombie.hpp"

int main()
{
	std::string str;
	str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "~~ print_address ~~" << std::endl;
	std::cout << "|- str_ptr   = " << &str << std::endl;
	std::cout << "|- stringPTR = " << stringPTR << std::endl;
	std::cout << "|- stringREF = " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "~~ print_valiable ~~" << std::endl;
	std::cout << "|- str         = " << str << std::endl;
	std::cout << "|- stringPTR-> = " << *stringPTR << std::endl;
	std::cout << "|- stringREF-> = " << stringREF << std::endl;
	std::cout << std::endl;

	str = "HI I AM BRAIN";

	std::cout << "~~ print_re_address ~~" << std::endl;
	std::cout << "|- str_ptr   = " << &str << std::endl;
	std::cout << "|- stringPTR = " << stringPTR << std::endl;
	std::cout << "|- stringREF = " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "~~ print_re_valiable ~~" << std::endl;
	std::cout << "|- str         = " << str << std::endl;
	std::cout << "|- stringPTR-> = " << *stringPTR << std::endl;
	std::cout << "|- stringREF-> = " << stringREF << std::endl;

	return (0);
}
