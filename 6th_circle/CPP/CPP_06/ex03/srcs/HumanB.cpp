/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:15:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/23 21:15:34 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : name(str),bring_wep(NULL)
{
}

void HumanB::setWeapon(Weapon &new_wep)
{
	this->bring_wep = &new_wep;
}

void HumanB::attack()
{
	if(this->bring_wep != NULL)
		std::cout << this->name << " attacks with their " << this->bring_wep->getType() << std::endl;
	else
		std::cout << this->name << " dont have weapon (;-;)" << std::endl;
}
