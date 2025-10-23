/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:15:36 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/23 21:15:36 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& wep) : name(str),bring_wep(wep)
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->bring_wep.getType() << std::endl;
}
