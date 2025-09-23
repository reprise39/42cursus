/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:00:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/23 03:29:52 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap(), _isGardMord(false)
{
	std::cout << blue << "<Scavtrap> Default constructor called" << reset << std::endl;
	ClapTrap::setAD(20);
	ClapTrap::setEP(50);
	ClapTrap::setHP(100);
}

ScavTrap::ScavTrap(std::string& str) : ClapTrap(str), _isGardMord(false)
{
	std::cout << blue << "<Scavtrap> String constructor called" << reset << std::endl;
	ClapTrap::setAD(20);
	ClapTrap::setEP(50);
	ClapTrap::setHP(100);
}
ScavTrap::~ScavTrap()
{
	std::cout << red << "<Scavtrap> Destructor called" << reset << std::endl;
}

void ScavTrap::guardGate()
{
	if(this->_isGardMord == false)
		std::cout << "<Scavtrap> " << ClapTrap::getName() << "turn on GateKeeper mode!" << std::endl;
	else
		std::cout << "<Scavtrap> " << ClapTrap::getName() << "is already GateKeeper mode..." << std::endl;
}
