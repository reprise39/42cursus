/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:13:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 21:47:31 by mkuida           ###   ########.fr       */
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
	if(0 <= n && n < 100 )
		this->_MyBrain->_Idea[n] = str;
	else
		std::cout << "makeIdea : error (out of range)" << std::endl;
}

std::string Cat::getIdea(const int n) const
{
	if(0 <= n && n < 100 )
		return (this->_MyBrain->_Idea[n]);
	else
		return ("getIdea : error (out of range)");
}

std::string Cat::printMyClass()const
{
	return ("< Cat > ");
}

