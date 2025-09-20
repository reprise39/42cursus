/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:35:15 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/20 13:54:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#ifndef FIXED_HPP
#include "Fixed.hpp"
#define FIXED_HPP
#endif

class Point
{
public:
	Point();
	Point(float x, float y);
	Point(const Point &dup);
	~Point();

	Point &operator=(const Point &other);

private:
	Fixed _x;
	Fixed _y;
};

#endif