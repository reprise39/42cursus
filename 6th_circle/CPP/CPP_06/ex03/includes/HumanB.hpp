/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:43:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:43:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

// include
# include <string>
# include <iostream>
# include "Weapon.hpp"
// macro

// class
class HumanB
{
	public:
		void attack();
		HumanB(std::string str);
		void setWeapon(Weapon &new_wep);
	private:
		std::string name;
		Weapon *bring_wep;
};

#endif