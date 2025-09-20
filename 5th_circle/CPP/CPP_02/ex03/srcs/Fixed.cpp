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
	std::cout << blue << "Default constructor called" << reset << std::endl;
	this->_fp_n = 0;
}

Fixed::Fixed(int i)
{
	std::cout << blue << "Int constructor called" << reset << std::endl;
	this->_fp_n = i << (this->_fractional_bit);
}

Fixed::Fixed(float f)
{
	std::cout << blue << "Float constructor called" << reset << std::endl;

	this->_fp_n = ((int)roundf(f * (1 << this->_fractional_bit)));
}

Fixed::Fixed(const Fixed& c)
{
	std::cout << blue << "Copy constructor called" << reset << std::endl;
	*this = c;
}

Fixed::~Fixed()
{
	std::cout << red << "Destructor called" << reset << std::endl;
	std::cout << this->toFloat() << std::endl;
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

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

//operator
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	//kansyu : memory,soket ... else
	if (this != &other)
	{
		this->_fp_n = other.getRawBits();
	}
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	int newbit = this->_fp_n + other.getRawBits();
	Fixed rtn;
	rtn.setRawBits(newbit);
	return (rtn);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	int newbit = this->_fp_n - other.getRawBits();
	Fixed rtn;
	rtn.setRawBits(newbit);
	return (rtn);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	int newbit = this->_fp_n * other.getRawBits();
	(newbit) = (newbit) >> (this->_fractional_bit);
	Fixed rtn;
	rtn.setRawBits(newbit);
	return (rtn);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	int newbit = this->_fp_n / other.getRawBits();
	(newbit) = (newbit) << (this->_fractional_bit);
	Fixed rtn;
	rtn.setRawBits(newbit);
	return (rtn);
}

Fixed& Fixed::operator++()
{
	(this->_fp_n)++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fp_n++;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	(this->_fp_n)--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fp_n--;
	return (tmp);
}

bool Fixed::operator<(const Fixed& other) const
{
	if(this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed& other) const
{
	if(this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if(this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if(this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if(this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if(this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

std::ostream& operator<<(std::ostream& os,const Fixed& fixed)
{
	return (os << fixed.toFloat());
}
