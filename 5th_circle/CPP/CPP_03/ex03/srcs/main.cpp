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

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}

std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& blue(std::ostream& os)
{
	return (os << "\033[34m");
}

std::ostream& yellow(std::ostream& os)
{
	return (os << "\033[33m");
}

static bool is_same(const Point &a, const Point &b, const Point &c)
{
	if (a == b || b == c || c == a)
	{
		std::cout << "this is not rectangle ( give same point )" << std::endl;
		return (true);
	}
	return (false);
}

static float get_cross_product(const Point &a, const Point &b)
{
	return ((a.getX().toFloat()) * (b.getY().toFloat()) - (a.getY().toFloat()) * (b.getX().toFloat()));
}

static bool is_line(const Point &a, const Point &b, const Point &c)
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

static bool is_triangle(const Point &a, const Point &b, const Point &c)
{
	if (is_same(a, b, c) == true)
		return (false);
	if (is_line(a, b, c) == true)
		return (false);
	return true;
}

static bool isin_triangle(const Point &a, const Point &b, const Point &c, const Point &p)
{
	Point a_to_b(b-a);
	// std::cout << "vector : a->b" << std::endl;
	// a_to_b.print();

	Point a_to_p(p-a);
	// std::cout << "vector : a->p" << std::endl;
	// a_to_p.print();

	Point b_to_c(c-b);
	// std::cout << "vector : b->c" << std::endl;
	// b_to_c.print();

	Point b_to_p(p-b);
	// std::cout << "vector : b->p" << std::endl;
	// b_to_p.print();

	Point c_to_a(a-c);
	// std::cout << "vector : c->a" << std::endl;
	// c_to_a.print();

	Point c_to_p(p-c);
	// std::cout << "vector : c->p" << std::endl;
	// c_to_p.print();

	float cp_a = get_cross_product(a_to_b, a_to_p);
	float cp_b = get_cross_product(b_to_c, b_to_p);
	float cp_c = get_cross_product(c_to_a, c_to_p);
	// std::cout << cp_a << ", " <<  cp_b << ", " << cp_c << std::endl;

	if (cp_a < 0 && cp_b < 0 && cp_c < 0)
		return (true);
	else if (cp_a > 0 && cp_b > 0 && cp_c > 0)
		return (true);
	else if (cp_a == 0 || cp_b == 0 || cp_c == 0)
	{
		std::cout << "on rectangle ( = is not inside ) " << std::endl;
		return (false);
	}
	return (false);
}

static bool bsp(const Point &a, const Point &b, const Point &c, const Point &p)
{
	if (is_triangle(a, b, c) == false)
		return (false);
	if (isin_triangle(a, b, c, p) == false)
		return (false);
	return (true);
}

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(4, 4);
	Point point(4, 2);

	bool ans = bsp(a, b, c, point);

	if (ans == true)
		std::cout << yellow << "Conclude : inside rectangle!" << reset << std::endl;
	else
		std::cout << yellow << "Conclude : outside rectangle!" << reset << std::endl;

	return 0;
}
