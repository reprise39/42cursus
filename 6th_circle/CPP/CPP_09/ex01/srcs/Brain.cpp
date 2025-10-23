/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:00:25 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/28 14:26:22 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

Brain::~Brain()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_Idea[i] = other._Idea[i];
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

void Brain::setIdea(const int inum, const std::string &str)
{
	if (inum < 0 || inum >= 100)
	{
		std::cout << "setIdea : fail (invalid num)" << std::endl;
		return;
	}
	this->_Idea[inum] = str;
	return;
}

std::string Brain::getIdea(int inum) const
{
	if (inum < 0 || inum >= 100)
		return ("getIdea : fail (invalid num)");
	return (this->_Idea[inum]);
}

std::string Brain::printMyClass() const
{
	return ("< Brain > ");
}
