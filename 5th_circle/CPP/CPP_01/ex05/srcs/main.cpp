/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:48:37 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/15 09:25:59 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl test;

	std::string str_vec[] = 
	{
		"a",
		" ",
		"DEBUG",
		"ERROR",
		"WARNING"
	};

	for(unsigned int i = 0 ; i < sizeof(str_vec)/sizeof(str_vec[0]) ; i++)
		test.complain(str_vec[i]);

	std::cout << std::endl << "\033[1m" << "after this line format output" << "\033[0m" << std::endl << std::endl;
	
	for(unsigned int i = 0 ; i < sizeof(str_vec)/sizeof(str_vec[0]) ; i++)
		test.formatprint(str_vec[i]);
	
	return (0);
}

