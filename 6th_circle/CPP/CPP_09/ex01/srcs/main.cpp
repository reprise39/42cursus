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

#include "RPN.hpp"

// static int check_using_c(char *argv)
// {
// 	size_t now = 0;
// 	const char acceptc[15] = { ' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/' };
// 	while(argv[now] != '\0')
// 	{
// 		bool check = false;
// 		for(size_t i = 0; i < 15 ; i++)
// 		{
// 			if(acceptc[i] == argv[now])
// 				check = true;
// 		}
// 		if(check == false)
// 		{
// 			std::cout << argv[now] << " is forbidden!" << std::endl;
// 			return (1);
// 		}
// 		now++;
// 	}
// 	return (0);
// }

static int check_arg(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << red  << "Error\n" << "This program accepts only one argument" << reset <<  std::endl;
		return (1);
	}

	size_t now = 0;
	while (argv[1][now] != '\0')
	{
		if(!(is_my_digit(argv[1][now]) || is_my_operator(argv[1][now]) || is_my_brank(argv[1][now])))
		{
			std::cout << red << "Error\n" << "at input -> " << argv[1][now] << " : This program only can use { 0-9, +, -, *, / }" << reset <<  std::endl;
			return (1);
		}
		now++;
	}
	return (0);
}

int main(int argc, char** argv)
{
	if (check_arg(argc,argv) != 0)
		return (1);
	cal(argv[1]);
	return 0;
}
