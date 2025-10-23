/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 12:20:16 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Cat::Cat(const std::string &str) : Animal("Cat")
{
	(void)str;

	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Cat& Cat::operator= (const Cat &other)
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

void Cat::makeSound()const
{
	std::cout << this->getType() << " make sound " << "[ Meow ]" << std::endl;
}

std::string Cat::printMyClass()const
{
	return ("< Cat > ");
}

