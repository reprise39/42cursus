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

#include "ClapTrap.hpp"

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

int main() {

	std::cout << "=== Test 1: Constructor / Destructor ===" << std::endl;
	{
		ClapTrap ct1("Alpha");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Basic attack ===" << std::endl;
	{
		ClapTrap ct2("Bravo");
		ct2.attack("TargetDummy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Take damage ===" << std::endl;
	{
		ClapTrap ct3("Charlie");
		ct3.takeDamage(3);
		ct3.takeDamage(5);
		ct3.takeDamage(5);
		ct3.takeDamage(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Repair ===" << std::endl;
	{
		ClapTrap ct4("Delta");
		ct4.takeDamage(6);
		ct4.beRepaired(4);
		ct4.beRepaired(20);
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy depletion ===" << std::endl;
	{
		ClapTrap ct5("Echo");
		for (int i = 0; i < 11; i++) {
			ct5.attack("Target");
		}
		ct5.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: No HP left ===" << std::endl;
	{
		ClapTrap ct6("Foxtrot");
		ct6.takeDamage(15);
		ct6.attack("Target");
		ct6.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: Multiple instances ===" << std::endl;
	{
		ClapTrap ct7a("Golf");
		ClapTrap ct7b("Hotel");

		ct7a.attack("Hotel");
		ct7b.takeDamage(2);
		ct7b.attack("Golf");
		ct7a.takeDamage(4);

		ct7a.beRepaired(3);
		ct7b.beRepaired(1);
	}
	std::cout << std::endl;

	std::cout << "=== Test 8: Copy constructor and assignment ===" << std::endl;
	{
		ClapTrap ct8a("India");
		ct8a.attack("Target");
		ClapTrap ct8b(ct8a);
		ct8b.attack("AnotherTarget");

		ClapTrap ct8c("Juliet");
		ct8c = ct8a;
		ct8c.attack("ThirdTarget");
	}
	std::cout << std::endl;

	return 0;
}