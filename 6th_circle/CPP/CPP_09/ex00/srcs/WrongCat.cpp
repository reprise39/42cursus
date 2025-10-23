/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 00:51:20 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

WrongCat::WrongCat(const std::string &str) : WrongAnimal("WrongCat")
{
	(void)str;

	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat &other)
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

void WrongCat::makeSound()const
{
	std::cout << this->getType() << " make sound " << "[ Meow ]" << std::endl;
}

std::string WrongCat::printMyClass()const
{
	return ("< WrongCat > ");
}
