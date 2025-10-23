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

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n=== Test 1: Animal class ===" << std::endl;
	{
		const Animal* meta = new Animal();
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		delete meta;
	}

	std::cout << "\n=== Test 2: Dog / Cat ===" << std::endl;
	{
		const Animal* d = new Dog();
		const Animal* c = new Cat();
		d->makeSound();
		c->makeSound();
		delete d;
		delete c;
	}

	std::cout << "\n=== Test 3: WrongAnimal polymorphism ===" << std::endl;
	{
		const WrongAnimal* wa = new WrongCat();
		wa->makeSound(); // cat, but ...
		delete wa;
	}

	std::cout << "\n=== Test 4: getType ==" << std::endl;
	{
		Dog d;
		Cat c;
		std::cout << d.getType() << std::endl;
		std::cout << c.getType() << std::endl;
	}

	std::cout << "\n=== Test 5: Canonical - Dog copy ===" << std::endl;
	{
		Dog d1;
		Dog d2(d1);   // copy constructor
		Dog d3;
		d3 = d1;      // copy assignment
	}

	std::cout << "\n=== Test 6: Canonical - Cat copy ===" << std::endl;
	{
		Cat c1;
		Cat c2(c1);
		Cat c3;
		c3 = c1;
	}

	std::cout << "\n=== Test 7: Virtual destructor check ===" << std::endl;
	{
		Animal* a = new Dog();
		delete a; // all destruct
	}

	std::cout << "\n=== in Subject test ===" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output cat
		j->makeSound();
		meta->makeSound();

		//my_add_for_leak
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n=== WTest : wrong Subject test ===" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will not output the cat sound!
		meta->makeSound();

		delete meta;
		delete i;
	}

	std::cout << "\n=== Test ===" << std::endl;
	{
		Animal* wa = new Cat();
		delete wa; // can destruct
	}

	std::cout << "\n=== WTest : WrongAnimal destructor check ===" << std::endl;
	{
		WrongAnimal* wa = new WrongCat();
		delete wa; // cant destruct
	}

	return 0;
}