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

#ifndef FT_PHONBOOK_HPP
# define FT_PHONBOOK_HPP

// lib
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdio>
# include <sstream>

// my_class
# ifndef CONCAT_HPP
#  include "Contact.hpp"
# endif

# ifndef PHONEBOOK_HPP
#  include "Phonebook.hpp"
# endif

// sarch.cpp
void search(Phonebook &phonebook);

// utils_cio.cpp
void cin_line_clear(void);
void cin_all_clear(void);

std::string red(const std::string& text);
std::string yellow(const std::string& text);
std::string blue(const std::string& text);

//utils.c
bool str_is_space(std::string str);
int str_to_int(const std::string s, bool* success);
std::string int_to_str(int val);

#endif
