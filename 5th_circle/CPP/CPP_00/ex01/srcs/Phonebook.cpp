/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:05:49 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/12 19:06:19 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_phonebook.hpp"

void Phonebook::search(void)
{
	print_list();
	search_list();
}

void Phonebook::search_x(int index_num)
{
	std::cout << std::endl;
	std::cout << "   index         : " << index_num << std::endl;
	std::cout << "   first_name    : " << this->contact[index_num].get_first_name() << std::endl;
	std::cout << "   last_name     : " << this->contact[index_num].get_last_name() << std::endl;
	std::cout << "   nickname      : " << this->contact[index_num].get_nickname() << std::endl;
	std::cout << "   phone_number  : " << this->contact[index_num].get_phone_number() << std::endl;
	std::cout << "   darkest_secret: " << this->contact[index_num].get_darkest_seclet() << std::endl;
	std::cout << std::endl;
}



void Phonebook::print_list(void)
{
	std::cout << "   ---------------------------------------------" << std::endl;
	std::cout << "   |     index|first name| last name|  nickname|" << std::endl;
	std::cout << "   ---------------------------------------------" << std::endl;
	for(int i = 1 ; i < BOOK_SIZE ; i++ )
	{
		std::cout << "   ";
		print_line(int_to_str(i));
		print_line(this->contact[i].get_first_name());
		print_line(this->contact[i].get_last_name());
		print_line(this->contact[i].get_nickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "   ---------------------------------------------" << std::endl;
}

void Phonebook::search_list(void)
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
				std::cout << "   exit search" << std::endl;
				return ;
			}
			else
			{
				search_x(input_num);
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
