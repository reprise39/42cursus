/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/25 21:41:52 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int check_arg(int argc, char** argv)
{
	(void)argv;

	if(argc != 2)
	{
		std::cerr << "input error : ./convert {one-arg} is correct" << std::endl;
		return (1);
	}
	return (0);
}


int main(int argc, char** argv)
{
	if (check_arg(argc, argv) == 1)
		return (1);

	std::string input(argv[1]);
	ScalarConverter::convert(input);

	return (0);
}