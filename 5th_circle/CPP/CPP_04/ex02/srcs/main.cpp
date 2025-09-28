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

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// std::cout << "=== EX02 Test 1: Abstract class check ===" << std::endl;
	// {
	// 	Animal a; // cant compile
	// }

	std::cout << "\n=== EX02 Test 2: Polymorphism ===" << std::endl;
	{
		const Animal* d = new Dog();
		const Animal* c = new Cat();
		d->makeSound();
		c->makeSound();
		delete d;
		delete c;
	}

	std::cout << "\n=== EX02 Test 2: Polymorphism ===" << std::endl;
	{
		const Animal* c = new Cat();
		c->makeSound();
		c->Animal::makeSound();
		delete c;
	}

	return 0;
}

