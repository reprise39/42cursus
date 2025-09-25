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
    std::cout << "=== 抽象クラスのテスト ===" << std::endl;
    //Animal a;  // ❌ コンパイルエラーになる（Animalは抽象クラス）

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    j->makeSound(); // Dog の鳴き声
    i->makeSound(); // Cat の鳴き声

    delete j;
    delete i;

    std::cout << "\n=== 配列での多態性確認 ===" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int k = 0; k < size/2; ++k)
        animals[k] = new Dog();
    for (int k = size/2; k < size; ++k)
        animals[k] = new Cat();

    for (int k = 0; k < size; ++k)
        animals[k]->makeSound();

    for (int k = 0; k < size; ++k)
        delete animals[k];

    std::cout << "\n=== deep copy 確認 ===" << std::endl;
    Dog dog1;
    dog1.makeIdea(0, "Play with ball");
    Dog dog2 = dog1; // copy constructor

    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.makeIdea(0, "Eat food");

    std::cout << "dog1 idea (after change in dog2): " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea (after change in dog2): " << dog2.getIdea(0) << std::endl;

    return 0;
}

