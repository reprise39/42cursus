/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:01 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:26:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character() : _name("mkuida")
{
	for(int i = 0 ; i < 4 ; i++)
	{
		this->_inventory[i] = NULL;
	}
	std::cout 
		<< blue << this->printMyClass()
		<< "Default constructor called" << reset << std::endl;

}

Character::Character(std::string const & name) : _name(name)
{
	for(int i = 0 ; i < 4 ; i++)
	{
		this->_inventory[i] = NULL;
	}
	std::cout 
		<< blue << this->printMyClass()
		<< "String constructor called" << reset << std::endl;
}

Character::Character(const Character& other)
{
	*this = other;
	std::cout 
		<< blue << this->printMyClass()
		<< "Copy constructor called" << reset << std::endl;
}

Character::~Character()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
	std::cout
		<< red << this->printMyClass()
		<< "Destructor called" << reset << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for(int i = 0 ; i < 4 ; i ++)
		{
			if(this->_inventory[i] != NULL)
				delete (this->_inventory[i]);
			if(other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	else
		std::cout << this->printMyClass() << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* other)
{
	if(other == NULL)
	{
		std::cout << "equip : failer" << std::endl;
		return;
	}
	else
	{
		for(int i = 0 ; i < 4 ; i++)
		{
			if(this->_inventory[i] == NULL)
			{
				this->_inventory[i] = other;
				std::cout << "equip : success at slot " << i << std::endl;
				return;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if(idx < 0 && idx > 3)
	{
		std::cout << "unequip : failer ( unabaiable slot num )" << std::endl;
		return;
	}
	else
	{
		if(this->_inventory[idx] == NULL)
			std::cout << "unequip : failer ( already empty ) " << std::endl;
		else
		{
			std::cout << "unequip : success " << std::endl;
			this->_inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 || this->_inventory[idx] == NULL)
	{
		std::cout << "use : failer" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

std::string Character::printMyClass() const
{
	return ("< Character > ");
}
