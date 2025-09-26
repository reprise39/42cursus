/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 20:28:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->_MyBrain = new Brain();
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Cat::Cat(const std::string &str) : Animal("Cat")
{
	(void)str;
	this->_MyBrain = new Brain();

	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_MyBrain = new Brain(*(other._MyBrain));

	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

Cat::~Cat()
{
	delete this->_MyBrain;
	
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

