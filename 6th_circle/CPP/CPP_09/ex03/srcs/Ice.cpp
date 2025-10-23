/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:16:43 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 16:27:57 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

Ice::~Ice()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Ice& Ice::operator=(const AMateria& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* dest = new Ice();
	*dest = *this;
	return (dest);
}

void Ice::use(ICharacter& target)
{
	std::cout << yellow << "* shoots an ice bolt at " << target.getName() << " *" << reset << std::endl;
}

std::string Ice::printMyClass() const
{
	return ("< Ice > ");
}
