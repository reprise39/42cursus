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

static std::string getstring(std::ifstream& ifs)
{
	std::string line;
	std::string dest;
	while(std::getline(ifs,line))
	{
		dest += line;
		dest += "\n";
	}
	return (dest);
}

static int check_arg(int argc, char **argv)
{
	(void)**argv;
	if(argc != 4)
	{
		std::cout << red << "Error : This program needs 3 parameters" << reset << std::endl;
		std::cout << "  1st : filename" << std::endl;
		std::cout << "  2nd : replacrd word" << std::endl;
		std::cout << "  3rd : convert new word(from 2nd words)" << std::endl;
		std::cout << std::endl;
		return (1);
	}
	return (0);
}

static std::string replace(std::string str, char* b , char* a)
{
	std::string str_a(a); 
	std::string str_b(b);
	std::string dest;

	size_t start = 0;
	size_t p = str.find(str_b,start);
	while(p != std::string::npos)
	{
		dest += str.substr(start, p-start) + str_a;
		start = p + str_b.size();
		p = str.find(str_b,start);
	}
	dest += str.substr(start);
	return (dest);
}

std::string get_input(char *argv)
{
	std::ifstream rdfile;
	rdfile.open(argv);
	if(!rdfile.is_open())
	{
		std::cerr << red << "file cant open " << reset << std::endl;
		std::cerr << "check input file name and authority" << std::endl;
		exit (1);
	}
	std::string dest = getstring(rdfile);
	// std::cout << raw_string << std::endl;
	rdfile.close();
	return (dest);
}

void print_out(std::string& str, char *argv)
{
	std::string ofilename = std::string(argv) + ".replace";
	std::ofstream otfile(ofilename.c_str());
	if (!otfile.is_open())
	{
		std::cerr << red <<"cannot create output file" << std::endl;
		std::cerr << "check output filname ( {input}.replace) " << std::endl;
		exit (1);
	}
	otfile << str;
	otfile.close();
	std::cout << blue << "complete : check-> "  << ofilename << reset << std::endl;
	return ;
}


int main(int argc ,char **argv)
{
	if (check_arg(argc,argv) == 1)
		return (1);

	std::string raw_string = get_input(argv[1]);
	//nullcheck

	std::string out_string = replace(raw_string, argv[2], argv[3]);
	print_out(out_string, argv[1]);
	return (0);
}
