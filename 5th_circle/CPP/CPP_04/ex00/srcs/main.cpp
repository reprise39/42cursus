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
	std::cout << "\n=== EX00 Test 10: Subject test ===" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "=== EX00 Test 1: Animal base class ===" << std::endl;
	{
		const Animal* meta = new Animal();
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		delete meta;
	}

	std::cout << "\n=== EX00 Test 2: Dog / Cat polymorphism ===" << std::endl;
	{
		const Animal* d = new Dog();
		const Animal* c = new Cat();
		d->makeSound();
		c->makeSound();
		delete d;
		delete c;
	}

	std::cout << "\n=== EX00 Test 3: WrongAnimal polymorphism ===" << std::endl;
	{
		const WrongAnimal* wa = new WrongCat();
		wa->makeSound(); // WrongCatの音が出ないはず
		delete wa;
	}

	std::cout << "\n=== EX00 Test 5: getType check ===" << std::endl;
	{
		Dog d;
		Cat c;
		std::cout << d.getType() << std::endl;
		std::cout << c.getType() << std::endl;
	}

	std::cout << "\n=== EX00 Test 6: Canonical - Dog copy ===" << std::endl;
	{
		Dog d1;
		Dog d2(d1);   // copy constructor
		Dog d3;
		d3 = d1;      // copy assignment
	}

	std::cout << "\n=== EX00 Test 7: Canonical - Cat copy ===" << std::endl;
	{
		Cat c1;
		Cat c2(c1);
		Cat c3;
		c3 = c1;
	}

	std::cout << "\n=== EX00 Test 9: Virtual destructor check ===" << std::endl;
	{
		Animal* a = new Dog();
		delete a; // Dog destructor → Animal destructor が呼ばれる
	}

	// std::cout << "\n=== EX00 Test 10: wrong Subject test ===" << std::endl;
	// {
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	meta->makeSound();

	// 	delete meta;
	// 	delete i;
	// }

	// std::cout << "\n=== EX00 Test 10: WrongAnimal destructor check ===" << std::endl;
	// {
	// 	WrongAnimal* wa = new WrongCat();
	// 	delete wa; // WrongCatのデストラクタが呼ばれない可能性確認
	// }

	return 0;
}