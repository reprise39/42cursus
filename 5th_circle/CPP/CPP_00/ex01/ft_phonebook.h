/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phonbook.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:43:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:43:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHONBOOK_H
# define FT_PHONBOOK_H

//
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdio>
# include <sstream>

//
# define BOOK_SIZE 9

//


class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string phone_number;
		std::string darkest_seclet;
	private:
};

class Phonebook
{
	public:
		void init_phonebook();
		Contact contact[BOOK_SIZE + 1];
	private:
};

// sarch.cpp
void search(Phonebook &phonebook);

// utils_cio.cpp
void cin_line_clear(void);
void cin_all_clear(void);
int str_to_int(const std::string s, bool* success);
std::string red(const std::string& text);
std::string yellow(const std::string& text);
std::string blue(const std::string& text);

#endif