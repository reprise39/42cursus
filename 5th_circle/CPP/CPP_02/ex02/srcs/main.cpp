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
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

