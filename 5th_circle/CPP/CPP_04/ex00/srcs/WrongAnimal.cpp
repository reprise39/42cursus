/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:26:23 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 19:26:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _Type("No Name")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& str) : _Type(str) 
{
	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& c)
{
	std::cout 
	<< blue << this->printMyClass()
	<< "Copy constructor called" << reset << std::endl;
	*this = c;
}

WrongAnimal::~WrongAnimal()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	// std::cout << this->printMyClass() << "Copy assignment operator called" << std::endl;
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		this->_Type = other._Type;
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

std::string WrongAnimal::printMyClass() const
{
	return ("< WrongAnimal > ");
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " make sounds " << "[ ??? ]" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_Type);
}

void WrongAnimal::setType(const std::string& str)
{
	this->_Type = str;
}
