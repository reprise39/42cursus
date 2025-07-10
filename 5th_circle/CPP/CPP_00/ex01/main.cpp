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

# include "ft_phonebook.h"

std::string get_str(std::string print_word)
{
	std::string input;
	while(1)
	{
		std::cout << "   " << std::right << "prease type : " << print_word << " : ";
		std::getline(std::cin,input);
		if(input != "")
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
		phonebook.contact[BOOK_SIZE - i].first_name = phonebook.contact[BOOK_SIZE - 1 - i].first_name;
		phonebook.contact[BOOK_SIZE - i].last_name = phonebook.contact[BOOK_SIZE - 1 - i].last_name;
		phonebook.contact[BOOK_SIZE - i].nickname = phonebook.contact[BOOK_SIZE - 1 - i].nickname;
		phonebook.contact[BOOK_SIZE - i].phone_number = phonebook.contact[BOOK_SIZE - 1 - i].phone_number;
		phonebook.contact[BOOK_SIZE - i].darkest_seclet = phonebook.contact[BOOK_SIZE - 1 - i].darkest_seclet;
	}
}

void add(Phonebook &phonebook)
{
	std::string str;

	phonebook.contact[0].first_name = get_str("1_first name    ");
	phonebook.contact[0].last_name = get_str("2_last name     ");
	phonebook.contact[0].nickname = get_str("3_nickname      ");
	phonebook.contact[0].phone_number = get_str("4_phone number  ");
	phonebook.contact[0].darkest_seclet = get_str("5_darkest secret");
	add_phonebook(phonebook);
	std::cout << "   exit add" << std::endl;
}

int main()
{
	Phonebook phonebook;
	std::string input_str;

	while(1)
	{
		// cin_all_clear();
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