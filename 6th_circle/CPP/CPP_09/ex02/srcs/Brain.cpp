/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:00:25 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 12:21:13 by mkuida           ###   ########.fr       */
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

Brain& Brain::operator= (const Brain &other)
{
	// kansyu : memory,soket ... else
	if (this != &other)
	{
		for(int i = 0 ; i < 100 ; i++)
			this->_Idea[i] = other._Idea[i];
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

std::string Brain::printMyClass()const
{
	return ("< Brain > ");
}

