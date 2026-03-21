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

static int check_arg(int argc, char** argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		std::cout << red  << "Error : " << "This program accepts only one argument" << reset <<  std::endl;
		return (1);
	}

	return (0);
}

int main(int argc, char** argv)
{
	if (check_arg(argc,argv) != 0)
		return (1);

	try
	{
		RPN my_rpn(argv[1]);
		my_rpn.print_ans();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
