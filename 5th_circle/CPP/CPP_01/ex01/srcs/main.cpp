/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:24:17 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/12 22:25:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::ostream& red(std::ostream& os)
{
	return os << "\033[31m";
}
std::ostream& blue(std::ostream& os)
{
	return os << "\033[34m";
}
std::ostream& reset(std::ostream& os)
{
	return os << "\033[0m";
}

int main()
{
	Zombie *zonp;

	zonp = zombieHorde( 5 , "5_bro" );
	delete[] zonp;

	return (0);
}
