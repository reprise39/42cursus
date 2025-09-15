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
	std::cout << this->name << " attacks with their " << this->bring_wep->getType() << std::endl;
}
