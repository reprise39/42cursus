/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:14:33 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/23 16:58:42 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap()
{
	std::cout << blue << this->printMyClass() << "Default constructor called" << reset << std::endl;
	ClapTrap::setAD(30);
	ClapTrap::setEP(100);
	ClapTrap::setHP(100);
}

FlagTrap::FlagTrap(const std::string &str) : ClapTrap(str)
{
	std::cout << blue << this->printMyClass() << "String constructor called" << reset << std::endl;
	ClapTrap::setAD(30);
	ClapTrap::setEP(100);
	ClapTrap::setHP(100);
}

FlagTrap::FlagTrap(const FlagTrap &c) : ClapTrap(c)
{
	std::cout << blue << this->printMyClass() << "String constructor called" << reset << std::endl;
	*this = c;
}

FlagTrap::~FlagTrap()
{
	std::cout << red << this->printMyClass() << "Destructor called" << reset << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	std::cout << this->printMyClass() << "Copy assignment operator called" << std::endl;
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

std::string FlagTrap::printMyClass() const
{
	return ("<FlagTrap> ");
}

void FlagTrap::highFivesGuys(void)
{
	std::cout << this->printMyClass() << "want you to hoght touch (._.)/"  << std::endl;
}