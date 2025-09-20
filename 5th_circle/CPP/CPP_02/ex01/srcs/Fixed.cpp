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

//structor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fp_n = 0;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fp_n = i << (this->_fractional_bit);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;

	this->_fp_n = ((int)roundf(f * (1 << this->_fractional_bit)));
}

Fixed::Fixed(const Fixed& c)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = c;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//function
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_n);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	(this->_fp_n) = raw;
}

float Fixed::toFloat( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	float ans =  ((float)(this->_fp_n)) / (1 << (this->_fractional_bit));
	return (ans);
}

int Fixed::toInt( void ) const
{
	return (roundf((getRawBits() >> 8)));
}

//operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//kansyu : memory,soket ... else
	if(this != &other)
	{
		this->_fp_n = other.getRawBits();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os,const Fixed& fixed)
{
	return (os << fixed.toFloat());
}