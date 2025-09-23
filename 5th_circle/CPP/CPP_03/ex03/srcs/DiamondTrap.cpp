/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:38:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 00:49:37 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FlagTrap(), ScavTrap()
{
	
}

DiamondTrap::DiamondTrap(const std::string& str) : ClapTrap(str) , FlagTrap(), ScavTrap()
{
	
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(), FlagTrap(), ScavTrap()
{
	std::cout << blue << this->printMyClass() << "String constructor called" << reset << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << red << this->printMyClass() << "Destructor called" << reset << std::endl;
}

void DiamondTrap::WhoAmI() //in work
{
	std::cout << this->printMyClass() << "who am i"  << std::endl;
}

std::string DiamondTrap::printMyClass() const
{
	return ("<DiamondTrip> ");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << this->printMyClass() << "Copy assignment operator called" << std::endl;
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->DiamondTrap::_Name = other.DiamondTrap::_Name;
		if(other.getGg() == true)
			this->setActiveGg();
		else
			this->setNegativeGg();
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}