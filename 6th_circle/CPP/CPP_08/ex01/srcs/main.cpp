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
#include "ScavTrap.hpp"

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
		ScavTrap st1("Alpha");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Basic attack ===" << std::endl;
	{
		ScavTrap st2("Bravo");
		st2.attack("TargetDummy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Take damage ===" << std::endl;
	{
		ScavTrap st3("Charlie");
		st3.takeDamage(20);
		st3.takeDamage(50);
		st3.takeDamage(40);
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Repair ===" << std::endl;
	{
		ScavTrap st4("Delta");
		st4.takeDamage(60);
		st4.beRepaired(40);
		st4.beRepaired(80);
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy depletion ===" << std::endl;
	{
		ScavTrap st5("Echo");
		for (int i = 0; i < 51; i++) {
			st5.attack("Target");
		}
		st5.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: No HP left ===" << std::endl;
	{
		ScavTrap st6("Foxtrot");
		st6.takeDamage(200);
		st6.attack("Target");
		st6.beRepaired(50);
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: guardGate ability ===" << std::endl;
	{
		ScavTrap st7("Golf");
		st7.guardGate();
		st7.guardGate();
	}
	std::cout << std::endl;

	std::cout << "=== Test 8: Multiple instances ===" << std::endl;
	{
		ScavTrap st8a("Hotel");
		ScavTrap st8b("India");

		st8a.attack("India");
		st8b.takeDamage(30);

		st8b.attack("Hotel");
		st8a.takeDamage(20);

		st8a.beRepaired(10);
		st8b.guardGate();
	}
	std::cout << std::endl;

	std::cout << "=== Test 9: Copy constructor and assignment ===" << std::endl;
	{
		ScavTrap st9a("Juliet");
		st9a.attack("Target");

		ScavTrap st9b(st9a);
		st9b.attack("AnotherTarget");

		ScavTrap st9c("Kilo");
		st9c = st9a;
		st9c.attack("ThirdTarget");
	}
	std::cout << std::endl;

	return 0;
}