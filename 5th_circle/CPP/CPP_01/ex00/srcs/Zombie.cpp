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

# include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string input)
{
	name = input;
	std::cout << this->name << "is now created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

int main()
{
	Zombie *new_test1 = newZombie("new_test1");
	Zombie *new_test2 = newZombie("new_test2");
	new_test1->announce();
	delete (new_test1);
	new_test2->announce();
	randomChump("random_test1");
	randomChump("random_test2");
	delete (new_test2);
	return (0);
}