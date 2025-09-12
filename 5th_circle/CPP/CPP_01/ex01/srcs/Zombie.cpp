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

Zombie::Zombie()
{
	std::cout << blue << "no_name" << " is now created" << reset << std::endl;
}

Zombie::Zombie(std::string input)
{
	name = input;
	std::cout << blue << this->name << " is now created" << reset << std::endl;
}

Zombie::~Zombie()
{
	std::cout << red << "Zombie " << name << " is destroyed" << reset << std::endl;
}

void Zombie::setname(std::string namae)
{
	this->name = namae;
}
