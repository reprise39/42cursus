/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:14:33 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 20:24:19 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout
		<< blue << this->printMyClass() << this->getName() << " : "
		<< "Default constructor called" << reset << std::endl;
	ClapTrap::setAD(30);
	ClapTrap::setEP(100);
	ClapTrap::setHP(100);
}

FragTrap::FragTrap(const std::string &str) : ClapTrap(str)
{
	std::cout
		<< blue << this->printMyClass() << this->getName() << " : "
		<< "String constructor called" << reset << std::endl;
	ClapTrap::setAD(30);
	ClapTrap::setEP(100);
	ClapTrap::setHP(100);
}

FragTrap::FragTrap(const FragTrap &c) : ClapTrap(c)
{
	std::cout
		<< blue << this->printMyClass() << this->getName() << " : "
		<< "String constructor called" << reset << std::endl;
	*this = c;
}

FragTrap::~FragTrap()
{
	std::cout
		<< red << this->printMyClass() << this->getName() << " : "
		<< "Destructor called" << reset << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

std::string FragTrap::printMyClass() const
{
	return ("<FragTrap> ");
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->printMyClass() << "want you to hight touch (._.)/"  << std::endl;
}