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
	std::cout << blue << "<ClapTrap> " << "Default constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : _Name(str), _Hitpoint(10), _EnergyPoint(10) , _AttackDamage(0)
{
	std::cout << blue << "<ClapTrap> " << "String constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << blue << "<ClapTrap> " << "Copy constructor called" << reset << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout << red << "<ClapTrap> " << "Destructor called" << reset << std::endl;
}

void ClapTrap::attack( const std::string& target )
{
	if(this->_Hitpoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant attack (is already dead...) " <<  std::endl;
	}
	else if(this->_EnergyPoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant attack (no EP) " <<  std::endl;
	}
	else
	{
		std::cout << "<ClapTrap> " << this->_Name << " attacks "  << target << ", causing " << this->_AttackDamage << " points of damage!" <<  std::endl;
		this->_EnergyPoint--;
	}
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_Hitpoint == 0 )
	{
		std::cout << "<ClapTrap> " << this->_Name << " is alreadry HitPoint = 0" <<  std::endl;
		return ;
	}
	std::cout << "<ClapTrap> " << this->_Name << " take damage HP <"  << amount << ">" <<  std::endl;
	if (this->_Hitpoint - static_cast<int>(amount) > 0)
	{
		this->_Hitpoint -= static_cast<int>(amount);
	}
	else if (this->_Hitpoint - static_cast<int>(amount) <= 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " is died :(" <<  std::endl;
		this->_Hitpoint = 0;
	}
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if(this->_Hitpoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant repair (already dead... (;_;)/~ )" <<  std::endl;
	}
	if(this->_EnergyPoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant repair (no EP) " <<  std::endl;
	}
	else
	{
		std::cout << "<ClapTrap> " << this->_Name << " is repaired HP <"  << amount << ">" <<  std::endl;
		this->_Hitpoint += static_cast<int>(amount);

	}
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "<ClapTrap> " << "Copy assignment operator called" << std::endl;
	//kansyu : memory,soket ... else
	if(this != &other)
	{
		this->_Name = other._Name;
		this->_Hitpoint = other._Hitpoint;
		this->_EnergyPoint = other._EnergyPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	else
		std::cout << "<ClapTrap> " << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}
