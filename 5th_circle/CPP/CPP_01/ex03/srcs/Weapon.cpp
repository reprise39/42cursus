/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:15:29 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/23 21:15:29 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string str)
{
	this->type = str;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

Weapon::Weapon(std::string str)
{
	this->type = str;
}
