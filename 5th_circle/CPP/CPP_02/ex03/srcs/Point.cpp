/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:46:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/21 09:27:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(), _y()
{
}

Point::Point(int fx, int fy) : _x(fx), _y(fy)
{
}

Point::Point(float fx, float fy) : _x(fx), _y(fy)
{
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{
}

Point::Point(const Point &dup) : _x(dup._x), _y(dup._y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
	this->_x = other._x;
	this->_y = other._y;
	return (*this);
}

Point Point::operator-(const Point &other) const
{
	Point rtn(this->_x - other._x, this->_y - other._y);
	return (rtn);
}

bool Point::operator==(const Point &other) const
{
	if (this->_x != other._x)
		return (false);
	if (this->_y != other._y)
		return (false);
	return (true);
}

const Fixed &Point::getX() const
{
	return (this->_x);
}

const Fixed &Point::getY() const
{
	return (this->_y);
}

void Point::setX(const Fixed x)
{
	(this->_x) = x;
}

void Point::setY(const Fixed y)
{
	(this->_y) = y;
}


//
void Point::print(void)
{
	std::cout << "(" << this->_x << ", " << this->_y << ")" << std::endl;
}