/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:55 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/11 19:14:18 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_phonebook.hpp"

void Contact::set_first_name(std::string str)
{
	this->first_name = str;
}
void Contact::set_last_name(std::string str)
{
	this->last_name = str;	
}
void Contact::set_nickname(std::string str)
{
	this->nickname = str;
}
void Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}
void Contact::set_darkest_seclet(std::string str)
{
	this->darkest_seclet = str;
}

std::string Contact::get_first_name(void) const
{
	return (this->first_name);
}
std::string Contact::get_last_name(void) const
{
	return (this->last_name);
}
std::string Contact::get_nickname(void) const
{
	return (this->nickname);
}
std::string Contact::get_phone_number(void) const
{
	return (this->phone_number);
}
std::string Contact::get_darkest_seclet(void) const
{
	return (this->darkest_seclet);
}
