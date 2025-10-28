/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:42:46 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/28 11:47:13 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialiser.hpp"

Serialiser::Serialiser()
{
	std::cout << blue
		<< Serialiser::strMyClass() << strConstMsg() << reset << std::endl;
}

Serialiser::Serialiser(const Serialiser& cp)
{
	*this = cp;
	std::cout << blue
		<< Serialiser::strMyClass() << strConstMsg() << reset << std::endl;
}

Serialiser::~Serialiser()
{
	std::cout << red 
		<< Serialiser::strMyClass() << strDestMsg() << reset << std::endl;
}

Serialiser& Serialiser::operator=(const Serialiser& cp)
{
	if(this != &cp)
	{
		(void)cp;
	}
	return (*this);
}

//
const std::string Serialiser::strMyClass()
{
	return ("<class : Serialiser> ");
}

//main
uintptr_t Serialiser::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialiser::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
