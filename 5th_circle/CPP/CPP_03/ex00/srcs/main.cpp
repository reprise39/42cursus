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

# include "ClapTrap.hpp"

std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& blue(std::ostream& os)
{
	return (os << "\033[34m");
}

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}

int main( void )
{
	ClapTrap test;

	for(int i = 1 ; i < 15 ; i++)
	{
		std::cout << "i = " << i << std::endl;
		test.attack("mkuida");
	}

	test.beRepaired(1);

	for(int i = 1 ; i < 3 ; i++)
	{
		std::cout << "i = " << i << std::endl;
		test.attack("mkuida");
	}
	return 0;
}
