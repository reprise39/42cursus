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
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
		DiamondTrap dt1("Alpha");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Basic attack ===" << std::endl;
	{
		DiamondTrap dt2("Bravo");
		dt2.attack("TargetDummy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Take damage ===" << std::endl;
	{
		DiamondTrap dt3("Charlie");
		dt3.takeDamage(40);
		dt3.takeDamage(70);
		dt3.takeDamage(50);
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Repair ===" << std::endl;
	{
		DiamondTrap dt4("Delta");
		dt4.takeDamage(80);
		dt4.beRepaired(40);
		dt4.beRepaired(200);
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy depletion ===" << std::endl;
	{
		DiamondTrap dt5("Echo");
		for (int i = 0; i < 51; i++) {
			dt5.attack("Target");
		}
		dt5.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: No HP left ===" << std::endl;
	{
		DiamondTrap dt6("Foxtrot");
		dt6.takeDamage(150);
		dt6.attack("Target");
		dt6.beRepaired(50);
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: whoAmI ability ===" << std::endl;
	{
		DiamondTrap dt7("Golf");
		dt7.whoAmI();
	}
	std::cout << std::endl;

	std::cout << "=== Test 8: Multiple instances ===" << std::endl;
	{
		DiamondTrap dt8a("Hotel");
		DiamondTrap dt8b("India");

		dt8a.attack("India");
		dt8b.takeDamage(30);

		dt8b.attack("Hotel");
		dt8a.takeDamage(40);

		dt8a.beRepaired(20);
		dt8b.whoAmI();
	}
	std::cout << std::endl;

	std::cout << "=== Test 9: Copy constructor and assignment ===" << std::endl;
	{
		DiamondTrap dt9a("Juliet");
		dt9a.attack("Target");

		DiamondTrap dt9b(dt9a);
		dt9b.attack("AnotherTarget");

		DiamondTrap dt9c("Kilo");
		dt9c = dt9a;
		dt9c.attack("ThirdTarget");
	}
	std::cout << std::endl;

	return 0;
}
