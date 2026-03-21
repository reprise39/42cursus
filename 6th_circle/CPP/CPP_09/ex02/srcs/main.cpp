/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:40:44 by mkuida            #+#    #+#             */
/*   Updated: 2026/03/21 19:47:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm> 

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
		char bad;

		if(!(iss >> tmp) || tmp <= 0 || iss >> bad)
		{
			std::cerr << red << "input need positive integer" << reset << std::endl;
			return (1);
		}
		if(std::find(myvec.begin(), myvec.end(), tmp) != myvec.end())
		{
			std::cerr << red << "input need unique integer" << reset << std::endl;
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
