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
    std::cout << "=== Basic test ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound(); // Woof!
    cat->makeSound(); // Meow!

    delete dog;
    delete cat;

    std::cout << "\n=== Array test ===" << std::endl;
    const Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 4; i++)
        delete animals[i]; // virtual dtor が正しく機能するかチェック

    std::cout << "\n=== Deep copy test ===" << std::endl;
    Dog dog1;
	dog1.makeIdea(0, "Chase the ball");   // ← Dog に Brain へのアクセサを実装している想定
    Dog dog2 = dog1; // copy constructor (deep copy)

    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.makeIdea(0, "Eat food");

    std::cout << "dog1 idea (after dog2 modified): " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea (after dog2 modified): " << dog2.getIdea(0) << std::endl;

    return 0;
}
