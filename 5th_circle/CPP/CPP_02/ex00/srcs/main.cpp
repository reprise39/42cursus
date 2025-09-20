/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:40:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}

std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& blue(std::ostream& os)
{
	return (os << "\033[34m");
}

std::ostream& yellow(std::ostream& os)
{
	return (os << "\033[33m");
}

static void print_rule()
{
	std::cout << "At first print out in this assignment" << std::endl;
	std::cout << ".---------------------------------------------" << std::endl;
	std::cout << "|-" << red << "constructor " << reset << "is " << red << "red " << reset << "color" << std::endl;
	std::cout << "|-" << blue << "destructor " << reset << "is " << blue << "blue " << reset << "color" << std::endl;
	// std::cout << "constracter is " << red << "red " << reset << "color" << std::endl;
	// std::cout << "constracter is " << red << "red " << reset << "color" << std::endl;
	std::cout << "'---------------------------------------------" << std::endl;
	std::cout << std::endl;
}


int main( void )
{
	print_rule();

	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
