/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/30 11:18:01 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// in subject main
int main(void)
{
	std::cout << "\n== insubject-testcase ==\n" << std::endl;
	{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << "\n== my-testcase (check same value) ==\n" << std::endl;
	{
		int a = 10;
		int b = 10;

		std::cout << "&a = " << &a << std::endl;
		std::cout << "&b = " << &b << std::endl;
		std::cout << std::endl;
		
		std::cout << "&min( a, b ) = " << &::min( a, b ) << std::endl;
		std::cout << "&max( a, b ) = " << &::max( a, b ) << std::endl;
		std::cout << std::endl;

		std::cout << "&min( b, a ) = " << &::min( b, a ) << std::endl;
		std::cout << "&max( b, a ) = " << &::max( b, a ) << std::endl;
	}
	
	return (0);
}
