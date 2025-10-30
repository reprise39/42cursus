/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/29 21:51:02 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialiser.hpp"

int main()
{
	//set_Data
	Data data;
	data.name = "mkuida";
	Data *dptr = &data;
	
	std::cout << "==========(make)==========================" << std::endl;
	std::cout << "&data				= " << &data << std::endl;
	std::cout << "dptr				= " << dptr << std::endl;
	std::cout << "data.name			= " << data.name << std::endl;
	// std::cout << "static_cast<uintptr_t>(dptr)	= " << reinterpret_cast<uintptr_t>(dptr) << std::endl;

	uintptr_t serialized_data = Serialiser::serialize(dptr);
	Data* deserialized_data = Serialiser::deserialize(serialized_data);
	
	std::cout << "=========(remake)==========================" << std::endl;
	std::cout << "serialized_data			= " << serialized_data << std::endl;
	std::cout << "deserialized_data		= " << deserialized_data << std::endl;
	std::cout << "(deserialized_data)->name	= " << (deserialized_data)->name << std::endl;

	uintptr_t reserialized_data = Serialiser::serialize(deserialized_data);
	Data* redeserialized_data = Serialiser::deserialize(reserialized_data);
	
	std::cout << "==========(re-remake)==========================" << std::endl;
	std::cout << "reserialized_data		= " << reserialized_data << std::endl;
	std::cout << "redeserialized_data		= " << redeserialized_data << std::endl;
	std::cout << "(redeserialized_data)->name	= " << (redeserialized_data)->name << std::endl;

	
	return 0;
}
