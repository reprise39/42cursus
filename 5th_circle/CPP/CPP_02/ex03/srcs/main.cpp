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

# include "Bsp.hpp"

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

bool is_same(const Point a, const Point b, const Point c)
{
	if(a == b || b == c || c == a)
		return (true);
	return (false);
}

float get_inc(const Point a, const Point b)
{
	float ab_x = a._x - b._x;
	folat ab_y = a._y - b._y;

	retrun (ab_y/ab_x);
}

float get_sec(const Point a, flaot inc)
{
	retrun ((a._y) - (-1)*(a._x)*(inc));
}

bool is_line(const Point a, const Point b, const Point c)
{
	float ab_inc = get_inc(a,b);
	float a_sec = get_sec(a,ab_inc);

	float bc_inc = get_inc(b,c);
	float b_sec = get_sec(b,bc_inc);

	if(ab_inc == bc_inc && a_sec == b_sec)
		retrun (true);
	retrun (false);
}

bool is_triangle(const Point a, const Point b, const Point c, const Point point)
{
	if(is_same(a,b,c) == true)
		return (false);
	if(is_line(a,b,c) == true)
		return (false);
	return true;
}

bool isin_triangle(const Point a, const Point b, const Point c, const Point p)
{
	get_inc(a,b);
	get_
}


bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	if (is_triangle(a,b,c) == false)
		return (false);
	if (isin_triangle(a,b,c,p) == false)
		return (false);
	return (true);
}

int main( void )
{
	print_rule();

	// Point const a;
	// Point const b;
	// Point const c;
	// Point const point;

	Point a(1,1);
	Point b;
	Point c;
	Point point;


	bool ans = bsp(a, b, c, point);

	// if(ans == true)
	// 	std::cout << blue << "in rectangle!" << reset << std::endl;
	// else 
	// 	std::cout << red << "out of rectangle!" << reset << std::endl;

	return 0;
}

