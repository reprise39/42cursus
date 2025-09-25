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

int main( void )
{
	//test animal
	Animal test1;
	Animal test2("neko");
	Animal test3(test2);
	
	std::cout << test3.getType() << std::endl;
	test3.setType("uoo");
	std::cout << test3.getType() << std::endl;

	test3.makeSound();

	//test cat
	Cat c;
	c.makeSound();

	//test dog
	Dog dd("cat");
	dd.makeSound();
	

	return 0;
}
