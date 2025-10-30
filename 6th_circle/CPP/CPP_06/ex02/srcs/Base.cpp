/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:26:39 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/30 14:44:39 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base* generate(void)
{
	int swc = std::rand() % 3;
	// std::cout << "swc = " << swc << std::endl;

	switch(swc)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	std::string ans("");
	if(dynamic_cast<A*>(p) != NULL)
		ans += "A";
	else if(dynamic_cast<B*>(p) != NULL)
		ans += "B";
	else if(dynamic_cast<C*>(p) != NULL)
		ans += "C";
	std::cout << ans << std::endl;
}

// void identify(Base& p)
// {
// 	Base *ptr = &p;
// 	identify(ptr);
// }

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown" << std::endl;
}
