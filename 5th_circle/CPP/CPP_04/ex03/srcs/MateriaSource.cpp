/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:01 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:26:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		this->_learnMateria[i] = NULL;
	}
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;

}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for(int i = 0 ; i < 4 ; i ++)
	{
		if(other._learnMateria[i] != NULL)
			this->_learnMateria[i] = other._learnMateria[i]->clone();
		else
			this->_learnMateria[i] = NULL;
	}
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		if (this->_learnMateria[i] != NULL)
			delete (this->_learnMateria[i]);
	}
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for(int i = 0 ; i < 4 ; i ++)
		{
			if(this->_learnMateria[i] != NULL)
				delete (this->_learnMateria[i]);
			if(other._learnMateria[i] != NULL)
				this->_learnMateria[i] = other._learnMateria[i]->clone();
			else
				this->_learnMateria[i] = NULL;
		}
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* other)
{
	if(other == NULL)
	{
		std::cout << "learnMateria : lean no materia" << std::endl;
		return;
	}
	else
	{
		for(int i = 0 ; i < 4 ; i++)
		{
			if(this->_learnMateria[i] == NULL)
			{
				this->_learnMateria[i] = other->clone();
				std::cout << "learnMateria : success at slot " << i << " (" << other->getType() << ")" << std::endl;
				return;
			}
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const &str)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnMateria[i] && this->_learnMateria[i]->getType() == str)
		{
			std::cout << "createMateria : success (" << str << ")" << std::endl;
			return (this->_learnMateria[i]->clone());
		}
	}
	std::cout << "createMateria : failer (" << str << ")" << std::endl;
	return NULL;
}

std::string MateriaSource::printMyClass() const
{
	return ("< MateriaSource > ");
}
