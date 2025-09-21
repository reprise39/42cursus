/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:35:15 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/21 09:14:45 by mkuida           ###   ########.fr       */
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
	Point(int x, int y);
	Point(float x, float y);
	Point(Fixed x, Fixed y);
	Point(const Point &dup);
	~Point();

	void print(void);

	Point &operator=(const Point &other);
	Point operator-(const Point &other) const;
	bool operator==(const Point &other) const;

	const Fixed& getX() const;
	const Fixed& getY() const;
	void setX(const Fixed x);
	void setY(const Fixed y);

private:
	Fixed _x;
	Fixed _y;
};

#endif