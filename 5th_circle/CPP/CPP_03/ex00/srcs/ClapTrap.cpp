/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 01:43:28 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/21 01:43:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("NoName"), _Hitpoint(10), _EnergyPoint(10) , _AttackDamage(0)
{
	std::cout << blue << "Default constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << blue << "Copy constructor called" << reset << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout << red <<  "Destructor called" << reset << std::endl;
}

void ClapTrap::attack( const std::string& target )
{
	if(this->_EnergyPoint > 0)
	{
		std::cout << this->_Name << " attacks "  << target << ", causing " << this->_AttackDamage << " points of damage!" <<  std::endl;
		this->_EnergyPoint--;
	}
	else
		std::cout << this->_Name << " cant attack (no EP) " <<  std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << this->_Name << " take damage HP <"  << amount << ">" <<  std::endl;
	this->_Hitpoint -= static_cast<int>(amount);
}

void ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << this->_Name << " is repaired HP <"  << amount << ">" <<  std::endl;
	this->_Hitpoint += static_cast<int>(amount);
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout <<  "Copy assignment operator called" << std::endl;
	//kansyu : memory,soket ... else
	if(this != &other)
	{
		this->_Name = other._Name;
		this->_Hitpoint = other._Hitpoint;
		this->_EnergyPoint = other._EnergyPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	else
		std::cout << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}
