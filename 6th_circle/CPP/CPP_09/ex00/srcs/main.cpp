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

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include "sio.hpp"
#include <map>

static int is_file(const char* fname)
{
	std::ifstream rdfile;
	rdfile.open(fname);

	if(!rdfile.is_open())
		return (1);
	rdfile.close();
	return (0);
}

static int check(int argc, char* argv[])
{
	std::string emsg;
	int rtn = 0;

	if(argc != 2)
	{
		emsg.append("need 1 arg (bitcoin filename)\n");
		rtn = 1;
	}
	else if(is_file(argv[1]) != 0)
	{
		emsg.append("data-file cant open\n");
		rtn = 1;
	}
	if(is_file("input.csv") != 0)
	{
		emsg.append("input-file cant open\n");
		rtn = 1;
	}

	if(rtn == 1)
		std::cout << red << emsg << reset;
	return (rtn);
}


int main(int argc, char* argv[])
{
	if (check(argc,argv) != 0)
		return (1);

	std::map<std::string, double> db;
	makeDB(db, argv[1]);
	// printaans();

	return (0);
}
