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

#include "PergeMe.hpp"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		std::cerr << "can't caliculate : need int args" << std::endl;
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
			std::cerr << "input need integer" << std::endl;
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
