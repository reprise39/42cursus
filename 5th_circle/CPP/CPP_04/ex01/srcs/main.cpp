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
std::cout << "=== Test 1: makeIdea ===" << std::endl;
	{
		Dog d1;
		d1.makeIdea(0, "zero idea");
		d1.makeIdea(5, "five five");

		for(int i = 0 ; i < 10 ; i++)
			std::cout << "d1_idea[" << i << "] = " << d1.getIdea(i) << std::endl;
	}

	std::cout << "\n=== Test 2: double makeIdea ===" << std::endl;
	{
		Cat c1;
		c1.makeIdea(0, "go");

		Cat c2;
		c2 = c1; // rebrain

		c2.makeIdea(42, "42");
		std::cout << "c1 idea[0]: " << c2.getIdea(0) << std::endl;
		std::cout << "c2 idea[0]: " << c2.getIdea(42) << std::endl;
	}

	std::cout << "\n=== Test 4: getType ===" << std::endl;
	{
		Dog d;//dog
		Cat c;//cat
		std::cout << d.getType() << std::endl;
		std::cout << c.getType() << std::endl;

		Dog dd("inu");//dog
		Cat cd("neko");//cat
		std::cout << dd.getType() << std::endl;
		std::cout << cd.getType() << std::endl;
	}

	std::cout << "\n=== Test 5: Canonical Dog ===" << std::endl;
	{
		Dog d1;
		Dog d2(d1);//re-bra
		Dog d3;
		d3 = d1; //re-brain
	}

	std::cout << "\n=== Test 6: Canonical Cat ===" << std::endl;
	{
		Cat c1;
		Cat c2(c1);
		Cat c3;
		c3 = c1;
	}

	std::cout << "\n=== Test 7: Canonical Brain ===" << std::endl;
	{
		Brain b1;
			b1._Idea[22] = "check copy";
			b1._Idea[42] = "42-tokyo";
		Brain b2(b1);
		Brain b3;
		b3 = b1;

		std::cout << b2._Idea[22] << std::endl;
		std::cout << b3._Idea[42] << std::endl;
	}

	std::cout << "\n=== Test 8: Virtual destruct ===" << std::endl;
	{
		Animal* a = new Dog();
		delete a;
	}
}
