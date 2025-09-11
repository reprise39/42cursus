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

# include "ft_phonebook.hpp"

std::string get_str(std::string print_word)
{
	std::string input;
	while(1)
	{
		std::cout << "   " << std::right << "prease type : " << print_word << " : ";
		std::getline(std::cin,input);
		if(str_is_space(input) == false)
			return (input);
		else
			std::cout << red("      ! blank_inpt is forbidden !") << std::endl;
	}
}

void add_phonebook(Phonebook &phonebook)
{
	std::string str;

	for (int i = 1 ; i < BOOK_SIZE ; i++)
	{
		phonebook.contact[BOOK_SIZE - i].set_first_name(phonebook.contact[BOOK_SIZE - 1 - i].get_first_name());
		phonebook.contact[BOOK_SIZE - i].set_last_name(phonebook.contact[BOOK_SIZE - 1 - i].get_last_name());
		phonebook.contact[BOOK_SIZE - i].set_nickname(phonebook.contact[BOOK_SIZE - 1 - i].get_nickname());
		phonebook.contact[BOOK_SIZE - i].set_phone_number(phonebook.contact[BOOK_SIZE - 1 - i].get_phone_number());
		phonebook.contact[BOOK_SIZE - i].set_darkest_seclet(phonebook.contact[BOOK_SIZE - 1 - i].get_darkest_seclet());
	}
}

void add(Phonebook &phonebook)
{
	std::string str;

	phonebook.contact[0].set_first_name(get_str("1_first name    "));
	phonebook.contact[0].set_last_name(get_str("2_last name     "));
	phonebook.contact[0].set_nickname(get_str("3_nickname      "));
	phonebook.contact[0].set_phone_number(get_str("4_phone number  "));
	phonebook.contact[0].set_darkest_seclet(get_str("5_darkest secret"));

	add_phonebook(phonebook);
	std::cout << "   exit add" << std::endl;
}

int main()
{
	Phonebook phonebook;
	std::string input_str;

	while(1)
	{
		std::cout << "cmd_prompt_mode > ";
		std::getline(std::cin,input_str);
		if (input_str == "ADD")
			add(phonebook);
		else if (input_str == "SEARCH")
			search(phonebook);
		else if (input_str == "EXIT")
			break;
	}
	return (0);
}
