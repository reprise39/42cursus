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

ClapTrap::ClapTrap() : _Name("NoName"), _Hitpoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : _Name(str), _Hitpoint(10), _EnergyPoint(10) , _AttackDamage(0)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoint > 0)
	{
		std::cout
			<< this->printMyClass() << this->getName() << " attacks " << target
			<< ", causing " << this->getAD() << " points of damage!" << std::endl;
		this->_EnergyPoint--;
	}
	else
		std::cout << this->printMyClass() << this->getName() << " cant attack (no EP) " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->getHP() == 0)
	{
		std::cout << this->printMyClass() << this->getName() << " is alreadry HitPoint = 0" <<  std::endl;
		return ;
	}

	std::cout << this->printMyClass() << this->getName() << " take damage HP <" << amount << ">" << std::endl;

	if(this->getHP() - static_cast<int>(amount) >= 0)
		this->setHP(this->getHP() - static_cast<int>(amount));
	else
		this->setHP(0);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->getEP() > 0)
	{
		std::cout << this->printMyClass() << this->getName() << " is repaired HP <" << amount << ">" << std::endl;
		this->_Hitpoint += static_cast<int>(amount);
	}
	else
		std::cout << this->printMyClass() << this->getName() << " cant repair (no EP) " <<  std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << this->printMyClass() << "Copy assignment operator called" << std::endl;
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		this->_Name = other._Name;
		this->_Hitpoint = other._Hitpoint;
		this->_EnergyPoint = other._EnergyPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

void ClapTrap::setHP( int amount )
{
	this->_Hitpoint = amount;
}

void ClapTrap::setEP( int amount )
{
	this->_EnergyPoint = amount;
}

void ClapTrap::setAD( int amount )
{
	this->_AttackDamage = amount;
}

std::string ClapTrap::printMyClass(void) const
{
	return ("<ClapTrap> ");
}

const std::string& ClapTrap::getName() const
{
	return (this->_Name);
}

int ClapTrap::getHP() const
{
	return (this->_Hitpoint);
}

int ClapTrap::getEP() const
{
	return (this->_EnergyPoint);
}

int ClapTrap::getAD() const
{
	return (this->_AttackDamage);
}
