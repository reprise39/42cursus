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
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

