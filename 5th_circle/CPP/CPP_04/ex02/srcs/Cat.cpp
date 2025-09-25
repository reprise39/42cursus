/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 12:49:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
	this->_MyBrain = new Brain();
}

Cat::Cat(const std::string &str) : Animal("Cat")
{
	(void)str;

	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
	this->_MyBrain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
	this->_MyBrain = new Brain();
	*this = other;
}

Cat::~Cat()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
	delete this->_MyBrain;
}

Cat& Cat::operator= (const Cat &other)
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

void Cat::makeSound()const
{
	std::cout << this->getType() << " make sound " << "[ Meow ]" << std::endl;
}

void Cat::makeIdea(const int n,const std::string& str) const
{
	this->_MyBrain->_Idea[n] = str;
}

std::string Cat::getIdea(const int n) const
{
	return (this->_MyBrain->_Idea[n]);
}

std::string Cat::printMyClass()const
{
	return ("< Cat > ");
}

