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
	std::cout << blue << "<ClapTrap> " << "NoName" << " : " << "Default constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : _Name(str), _Hitpoint(10), _EnergyPoint(10) , _AttackDamage(0)
{
	std::cout << blue << "<ClapTrap> " << str << " : " << "String constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << blue << "<ClapTrap> " << c._Name << " : " << "Copy constructor called" << reset << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout << red << "<ClapTrap> " << this->_Name << " : " << "Destructor called" << reset << std::endl;
}

void ClapTrap::attack( const std::string& target )
{
	if(this->_Hitpoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant attack (already dead...) " <<  std::endl;
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
		std::cout << "<ClapTrap> " << this->_Name << " dont take damage (alreadry dead...)" <<  std::endl;
		return ;
	}
	std::cout << "<ClapTrap> " << this->_Name << " take damage "  << amount;
	if (this->_Hitpoint - static_cast<int>(amount) > 0)
	{
		this->_Hitpoint -= static_cast<int>(amount);
		std::cout << " (rest : " << this->_Hitpoint << ")" << std::endl;
	}
	else if (this->_Hitpoint - static_cast<int>(amount) <= 0)
	{
		this->_Hitpoint = 0;
		std::cout << " (rest : " << this->_Hitpoint << ")" << std::endl;
		std::cout << "<ClapTrap> " << this->_Name << " is died (;_;)/~ " <<  std::endl;
	}

}

void ClapTrap::beRepaired( unsigned int amount )
{
	if(this->_Hitpoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant repair (already dead...)" <<  std::endl;
	}
	else if(this->_EnergyPoint == 0)
	{
		std::cout << "<ClapTrap> " << this->_Name << " cant repair (no EP) " <<  std::endl;
	}
	else
	{
		std::cout << "<ClapTrap> " << this->_Name << " is repaired HP "  << amount;
		this->_Hitpoint += static_cast<int>(amount);
		std::cout << " (rest : " << this->_Hitpoint << " )" << std::endl;
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
