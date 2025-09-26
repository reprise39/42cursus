/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:16:43 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:01:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

Cure::~Cure()
{
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Cure& Cure::operator=(const AMateria& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* dest = new Cure();
	*dest = *this;
	return (dest);
}

void Cure::use(ICharacter& target)
{
	std::cout << yellow << "* heals  "<< target.getName() << "’s wounds *" << reset << std::endl;
}

std::string Cure::printMyClass() const
{
	return ("< Cure > ");
}
