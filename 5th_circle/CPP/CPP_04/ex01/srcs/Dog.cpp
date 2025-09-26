/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 20:21:07 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->_MyBrain = new Brain();
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Dog::Dog(const std::string &str) : Animal("Dog")
{
	(void)str;

	this->_MyBrain = new Brain();
	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_MyBrain = new Brain();
	*this = other;

	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

Dog::~Dog()
{
	delete this->_MyBrain;

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
		delete this->_MyBrain;
		this->_MyBrain = new Brain(*(other._MyBrain));
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

void Dog::makeSound()const
{
	std::cout << this->getType() << " make sound " << "[ Bow wow ]" << std::endl;
}

void Dog::makeIdea(const int n,const std::string& str) const
{
	this->_MyBrain->_Idea[n] = str;
}

std::string Dog::getIdea(const int n) const
{
	return (this->_MyBrain->_Idea[n]);
}

std::string Dog::printMyClass()const
{
	return ("< Dog > ");
}

