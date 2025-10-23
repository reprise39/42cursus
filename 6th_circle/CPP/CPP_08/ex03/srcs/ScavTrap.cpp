/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:00:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 20:14:33 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap(), _isGardMord(false)
{
	std::cout
		<< blue << this->printMyClass() << this->getName() << " : "
		<< "Default constructor called" << reset << std::endl;
	ClapTrap::setAD(20);
	ClapTrap::setEP(50);
	ClapTrap::setHP(100);
}

ScavTrap::ScavTrap(const std::string& str) : ClapTrap(str), _isGardMord(false)
{
	std::cout
		<< blue << this->printMyClass() << this->getName() << " : "
		<< "String constructor called" << reset << std::endl;
	ClapTrap::setAD(20);
	ClapTrap::setEP(50);
	ClapTrap::setHP(100);
}

ScavTrap::ScavTrap(const ScavTrap& c) : ClapTrap(c)
{
	std::cout
		<< blue << this->printMyClass() << this->getName() << " : "
		<< "String constructor called" << reset << std::endl;
	*this = c;
}

ScavTrap::~ScavTrap()
{
	std::cout
		<< red << this->printMyClass() << this->getName() << " : "
		<< "Destructor called" << reset << std::endl;
}

void ScavTrap::guardGate()
{
	if(this->getGg() == false)
	{
		std::cout << this->printMyClass() << ClapTrap::getName() << "turn on GateKeeper mode!" << std::endl;
		this->setActiveGg();
	}
	else
		std::cout << this->printMyClass() << ClapTrap::getName() << "is already GateKeeper mode..." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << this->printMyClass() << "Copy assignment operator called" << std::endl;
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		ClapTrap::operator=(other);
		if(other.getGg() == true)
			this->setActiveGg();
		else
			this->setNegativeGg();
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

std::string ScavTrap::printMyClass(void) const
{
	return ("<ScavTrap> ");
}

void ScavTrap::setActiveGg()
{
	if(this->getGg() == false)
	{
		this->_isGardMord = true;
	}
}

void ScavTrap::setNegativeGg()
{
	if(this->getGg() == true)
	{
		this->_isGardMord = false;
	}
}

bool ScavTrap::getGg() const
{
	return (this->_isGardMord);
}
