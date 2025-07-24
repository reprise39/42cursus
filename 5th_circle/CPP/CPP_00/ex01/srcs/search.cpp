/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:55 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/10 17:33:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_phonebook.hpp"

static void search_x(Phonebook &phonebook, int index_num)
{
	std::cout << std::endl;
	std::cout << "   index      : " << index_num << std::endl;
	std::cout << "   first_name : " << phonebook.contact[index_num].first_name << std::endl;
	std::cout << "   last_name  : " << phonebook.contact[index_num].last_name << std::endl;
	std::cout << "   nickname   : " << phonebook.contact[index_num].nickname << std::endl;
	std::cout << std::endl;
}

static void print_line(std::string str)
{
	std::cout << "|";
	if(str.length() < 10)
		std::cout << std::setw(10)  << std::right << str;
	else
	{
		for (int i = 0 ; i < 9 ; i++)
		{
			std::cout << str[i];
		}
		std::cout << '.';
	}
}

static void print_list(Phonebook &phonebook)
{
	std::cout << "   ---------------------------------------------" << std::endl;
	std::cout << "   |     index|first name| last name|  nickname|" << std::endl;
	std::cout << "   ---------------------------------------------" << std::endl;
	for(int i = 1 ; i < BOOK_SIZE ; i++ )
	{
		std::cout << "   ";
		print_line(int_to_str(i));
		print_line(phonebook.contact[i].first_name);
		print_line(phonebook.contact[i].last_name);
		print_line(phonebook.contact[i].nickname);
		std::cout << "|" << std::endl;
	}
	std::cout << "   ---------------------------------------------" << std::endl;
}

static void search_list(Phonebook &phonebook)
{
	std::string input_str;
	int input_num;
	bool to_str_ok;

	std::cout << blue("   please type index_number to print detail (to exit , type 0)") << std::endl;
	while(1)
	{
		std::cout << "   search_prompt_mode > ";
		std::getline(std::cin, input_str);
		input_num = str_to_int(input_str, &to_str_ok);
		if(to_str_ok == true)
		{
			if(input_num < 0 || input_num > 9)
			{
				std::cout << red("   out_of_rage int") << std::endl;
				std::cout << blue("   please type index_number to print detail (to exit , type 0)") << std::endl;
			}
			else if(input_num == 0)
			{
				std::cout << "   exit seach" << std::endl;
				return ;
			}
			else
			{
				search_x(phonebook, input_num);
				return ;
			}
		}
		else
		{
			std::cout << red("   input is not int") << std::endl;
			std::cout << blue("   please type index_number to print detail (to exit , type 0)") << std::endl;
		}
	}
}

void search(Phonebook &phonebook)
{
	print_list(phonebook);
	search_list(phonebook);
}