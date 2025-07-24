/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:34:14 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/11 14:34:14 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

static int check_arg(int argc, char **argv)
{
	if(argc != 3)
	{
		std::cout << "Error : This program needs 3 parameters" << std::endl;
		std::cout << "1st : filename" << std::endl;
		std::cout << "2nd : replacrd word" << std::endl;
		std::cout << "3rd : convert new word(from 2nd words)" << std::endl;
		std::cout << std::endl;
	}
}


int main(int argc ,char **argv)
{
	if (check_arg(argc,argv) == 1)
		return (1)

	return (0);
}
