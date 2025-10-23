/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:01 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:48:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria() : _type("NoName")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

AMateria::~AMateria()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		this->_type = other.getType();
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "*******************" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

std::string AMateria::printMyClass() const
{
	return ("< AMateria > ");
}