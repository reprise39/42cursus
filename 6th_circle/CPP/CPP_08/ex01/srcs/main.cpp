/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/22 03:35:30 by mkuida           ###   ########.fr       */
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
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//my excuting-time test
	// try
	// {
	// 	Span sp(10000);
	// 	sp.addRandomNumber(10000, 100000);
	// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }


	// try
	// {
	// 	Span sp(10);
	// 	std::vector<int> vec(10);
	// 	for (int i = 0; i < 10; ++i)
	// 		vec[i] = i;
	// 	sp.addNumber(vec.begin(), vec.end());
			
	// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	return 0;
}
