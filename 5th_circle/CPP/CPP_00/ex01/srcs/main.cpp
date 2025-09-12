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

int main()
{
	Phonebook phonebook;
	std::string input_str;

	while(1)
	{
		std::cout << "cmd_prompt_mode > ";
		std::getline(std::cin,input_str);
		if (input_str == "ADD")
			phonebook.add();
		else if (input_str == "SEARCH")
			phonebook.search();
		else if (input_str == "EXIT")
			break;
	}
	return (0);
}
