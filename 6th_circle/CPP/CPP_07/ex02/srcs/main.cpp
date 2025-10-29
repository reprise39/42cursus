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

# include "Array.hpp"

int main( void )
{
	//basic
	int a[] = {0,1,2,3,4,5};
	Array<int> ArrayA(6);

	ArrayA[0] = 0;
	ArrayA[1] = 1;
	ArrayA[2] = 2;
	ArrayA[3] = 3;
	ArrayA[4] = 4;
	ArrayA[5] = 5;

	std::cout << "A:[2]+[3]=" << ArrayA[2]+ArrayA[3] << std::endl;

	Array<int> B(ArrayA);
	std::cout << "B:[2]+[3]=" << B[2]+B[3] << std::endl;
	std::cout << "B:[4]+[5]=" << B[4]+B[5] << std::endl;


	//deep copy
	ArrayA[5] = 0;
	std::cout << "A:[5]=" << ArrayA[5] << std::endl;
	std::cout << "B:[5]=" << B[5] << std::endl;

	//out of arria access
	try
	{
		ArrayA[100] = 100;
		std::cout << "<1>" << "A:[100]=" << ArrayA[100] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "<1>" << e.what() << std::endl;
	}

	try
	{
		ArrayA[-1] = -1;
		std::cout << "<2>" << "A:[-1]=" << ArrayA[-1] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "<2>" << e.what() << std::endl;
	}


	return (0);
}

