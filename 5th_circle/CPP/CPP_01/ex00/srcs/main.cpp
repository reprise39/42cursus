/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:06:47 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/12 22:17:05 by mkuida           ###   ########.fr       */
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
	Zombie *new_test1 = newZombie("new_test1");
	Zombie *new_test2 = newZombie("new_test2");
	new_test1->announce();
	delete (new_test1);
	new_test2->announce();
	randomChump("random_test1");
	randomChump("random_test2");
	delete (new_test2);
	return (0);
}
