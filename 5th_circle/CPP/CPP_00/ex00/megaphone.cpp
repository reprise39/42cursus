/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:49 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:40:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc,char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1 ; i < argc ; i++)
	{
		for (int j = 0 ; argv[i][j] != '\0' ; j++)
			std::cout << (char)toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
