/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:00:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/23 13:09:22 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap(), _isGardMord(false)
{
	std::cout << blue << this->printMyClass() << "Default constructor called" << reset << std::endl;
	ClapTrap::setAD(20);
	ClapTrap::setEP(50);
	ClapTrap::setHP(100);
}

ScavTrap::ScavTrap(const std::string& str) : ClapTrap(str), _isGardMord(false)
{
	std::cout << blue << this->printMyClass() << "String constructor called" << reset << std::endl;
	ClapTrap::setAD(20);
	ClapTrap::setEP(50);
	ClapTrap::setHP(100);
}

ScavTrap::ScavTrap(const ScavTrap& c)
{
	std::cout << blue << this->printMyClass() << "String constructor called" << reset << std::endl;
	*this = c;
}

ScavTrap::~ScavTrap()
{
	std::cout << red << this->printMyClass() << "Destructor called" << reset << std::endl;
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
