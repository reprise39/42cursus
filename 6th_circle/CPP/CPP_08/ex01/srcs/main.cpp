/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/11/04 11:59:40 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sio.hpp"
#include "Span.hpp"

// in subject main
int main(void)
{
	// insubject test
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//time test
	std::srand(std::time(NULL));

	// try
	// {
	// 	Span sp(10000); // 10,000

	// 	for (int i = 0; i < 10000; ++i)
	// 	// for (int i = 0; i < 10001; ++i)
	// 	// for (int i = 0; i < 1; ++i)
	// 	{
	// 		sp.addNumber(std::rand() % 100000); //0~10,000
	// 	}

	// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	return 0;
}
