/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:34:14 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/11 14:34:14 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fp_n(0)
{
	std::cout << blue << "Default constructor called" << reset << std::endl;
}

Fixed::Fixed(const Fixed& c)
{
	std::cout << blue << "Copy constructor called" << reset << std::endl;
	*this = c;
}

Fixed::~Fixed()
{
	std::cout << red << "Destructor called" << reset << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_n);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	(this->_fp_n) = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//kansyu : memory,soket ... else
	if(this != &other)
		this->_fp_n = other.getRawBits();
	else
		std::cout << "Copy assignment doesnt work ( same pointer )" << std::endl;
	return (*this);
}
