/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:40:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bsp.hpp"

static void print_rule()
{
	std::cout << "At first print out in this assignment" << std::endl;
	std::cout << ".---------------------------------------------" << std::endl;
	std::cout << "|-" << red << "constructor " << reset << "is " << red << "red " << reset << "color" << std::endl;
	std::cout << "|-" << blue << "destructor " << reset << "is " << blue << "blue " << reset << "color" << std::endl;
	// std::cout << "constracter is " << red << "red " << reset << "color" << std::endl;
	// std::cout << "constracter is " << red << "red " << reset << "color" << std::endl;
	std::cout << "'---------------------------------------------" << std::endl;
	std::cout << std::endl;
}

bool is_same(const Point &a, const Point &b, const Point &c)
{
	if (a == b || b == c || c == a)
	{
		std::cout << "this is not rectangle ( give same point )" << std::endl;
		return (true);
	}
	return (false);
}

float get_cross_product(const Point &a, const Point &b)
{
	return ((a.getX().toFloat()) * (b.getY().toFloat()) - (a.getY().toFloat()) * (b.getX().toFloat()));
}

bool is_line(const Point &a, const Point &b, const Point &c)
{
	float ab_cp = get_cross_product(a, b);
	float bc_cp = get_cross_product(b, c);

	if (ab_cp == 0 && bc_cp == 0)
	{
		std::cout << "this is not rectangle ( give on line point )" << std::endl;
		return (true);
	}
	return (false);
}

bool is_triangle(const Point &a, const Point &b, const Point &c)
{
	if (is_same(a, b, c) == true)
		return (false);
	if (is_line(a, b, c) == true)
		return (false);
	return true;
}

bool isin_triangle(const Point &a, const Point &b, const Point &c, const Point &p)
{
	float cp_a = get_cross_product(a, p);
	float cp_b = get_cross_product(b, p);
	float cp_c = get_cross_product(c, p);

	if (cp_a < 0 && cp_b < 0 && cp_c < 0)
		return (true);
	else if (cp_a > 0 && cp_b > 0 && cp_c > 0)
		return (true);
	return (false);
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &p)
{
	if (is_triangle(a, b, c) == false)
		return (false);
	if (isin_triangle(a, b, c, p) == false)
		return (false);
	return (true);
}

int main(void)
{
	print_rule();

	// Point const a;
	// Point const b;
	// Point const c;
	// Point const point;

	Point a(1, 1);
	Point b(3, 3);
	Point c(3, 1);
	Point point(2, 2.25);

	bool ans = bsp(a, b, c, point);

	if (ans == true)
		std::cout << blue << "in rectangle!" << reset << std::endl;
	else
		std::cout << red << "out of rectangle!" << reset << std::endl;

	return 0;
}
