/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 12:20:25 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Dog::Dog(const std::string &str) : Animal("Dog")
{
	(void)str;

	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Dog& Dog::operator= (const Dog &other)
{
	// std::cout << this->printMyClass() << "Copy assignment operator called" << std::endl;
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		this->setType(other.getType());
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

void Dog::makeSound()const
{
	std::cout << this->getType() << " make sound " << "[ Bow wow ]" << std::endl;
}

std::string Dog::printMyClass()const
{
	return ("< Dog > ");
}

