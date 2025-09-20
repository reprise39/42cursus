/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:46:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/20 13:50:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(), _y()
{
}

Point::Point(float fx, float fy) : _x(fx), _y(fy)
{
}

Point::Point(const Point& dup) : _x(dup._x) , _y(dup._y)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& other)
{
	this->_x = other._x;
	this->_y = other._y;	
	return (*this);
}
