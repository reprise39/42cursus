/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:44 by mkuida            #+#    #+#             */
/*   Updated: 2026/03/16 21:32:15 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PergeMe.hpp"
#include "../includes/sio.hpp"
#include <sstream>

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		std::cerr << red << "can't caliculate : need int args" << reset << std::endl;
		return (1);
	}

	std::vector<int> myvec;
	std::deque<int> mydeq;

	for(int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		int tmp;

		if(!(iss >> tmp) || tmp < 0)
		{
			std::cerr << red << "input need integer" << reset << std::endl;
			return (1);
		}
		myvec.push_back(tmp);
		mydeq.push_back(tmp);
	}

	try
	{
		PergeMe Pm(myvec,mydeq);
		Pm.printAns();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return 0;
}
