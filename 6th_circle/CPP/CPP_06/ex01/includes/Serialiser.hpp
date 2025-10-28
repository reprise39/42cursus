/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:43:08 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/28 11:57:17 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISER_HPP
# define SERIALISER_HPP

#include "sio.hpp"

//uintpter
#include <stdint.h>

struct Data
{
	std::string name;
};

class Serialiser
{
	public:
		//canonical
		Serialiser();
		Serialiser(const Serialiser& cp);
		~Serialiser();
		Serialiser& operator=(const Serialiser& cp);

		//
		const std::string strMyClass();

		//main
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		virtual void test() = 0;
};

#endif