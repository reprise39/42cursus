/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:26:23 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 19:26:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _Type("No Name")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Animal::Animal(const std::string& str) : _Type(str) 
{
	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

Animal::Animal(const Animal& c)
{
	std::cout 
	<< blue << this->printMyClass()
	<< "Copy constructor called" << reset << std::endl;
	*this = c;
}

Animal::~Animal()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Animal& Animal::operator= (const Animal& other)
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

std::string Animal::printMyClass() const
{
	return ("< Animal > ");
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " make sounds " << "[ ??? ]" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_Type);
}

void Animal::setType(const std::string& str)
{
	this->_Type = str;
}
