/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:38:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 21:31:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _Name("NoName")
{
	std::cout 
		<< blue << this->printMyClass() << this->_Name << " : "
		<< "Default constructor called" << reset << std::endl;
	this->setHP(100);
	this->setAD(30);
}

DiamondTrap::DiamondTrap(const std::string& str) : ClapTrap(str + "_clap_name") , FragTrap(), ScavTrap(), _Name(str)
{
	std::cout 
		<< blue << this->printMyClass() << this->_Name << " : "
		<< "String constructor called" << reset << std::endl;
	this->setHP(100);
	this->setAD(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout
		<< blue << this->printMyClass() << this->_Name << " : "
		<< "Copy constructor called" << reset << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout
		<< red << this->printMyClass() << this->_Name << " : "
		<< "Destructor called" << reset << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout
		<< this->printMyClass() << "[ DiamondName : " << this->_Name << " ] [ ClapName : "
		<< this->getName() << " ]" << std::endl;
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
		FragTrap::operator=(other);
		this->DiamondTrap::_Name = other.DiamondTrap::_Name;
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}
