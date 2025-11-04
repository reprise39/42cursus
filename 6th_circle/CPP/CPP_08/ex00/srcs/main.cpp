/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/31 19:29:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

// in subject main
int main(void)

{
	// can't use initialization list (C++11~)
	// std::vector<int> arr = {0,1,2,3,4,5};

	// give head ptr & last ptr
	int arr[] = {0, 1, 2, 3, 4, 5};
	std::vector<int> intvec(arr, arr + sizeof(arr) / sizeof(int));

	// std::vector<int> intvec;
	// intvec.push_back(0);
	// intvec.push_back(1);
	// intvec.push_back(2);
	// intvec.push_back(3);
	// intvec.push_back(4);
	// intvec.push_back(5);

	try
	{
		std::vector<int>::iterator target1 = easyfind(intvec,5);
		std::cout << "target1 = " << *target1 << std::endl;

		std::vector<int>::iterator target2 = easyfind(intvec,10);
		std::cout << "target2 = " << *target2 << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
