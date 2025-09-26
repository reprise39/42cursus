/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 21:44:04 by mkuida           ###   ########.fr       */
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
	if(0 <= n && n < 100 )
		this->_MyBrain->_Idea[n] = str;
	else
		std::cout << "makeIdea : error (out of range)" << std::endl;
}

std::string Dog::getIdea(const int n) const
{
	if(0 <= n && n < 100 )
		return (this->_MyBrain->_Idea[n]);
	else
		return ("getIdea : error (out of range)");
}

std::string Dog::printMyClass()const
{
	return ("< Dog > ");
}

