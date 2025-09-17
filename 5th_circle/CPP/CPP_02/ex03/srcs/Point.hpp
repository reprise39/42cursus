/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:46:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/17 17:33:51 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(), _y()
{
}

Point::Point(float fx, float fy) : _x(fx), _y(fy)
{
}

Point::Point(Point& dup) : _x(dup.x) , _y(dup.y)
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
