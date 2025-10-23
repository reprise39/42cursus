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

#ifndef HUMANA_HPP
# define HUMANA_HPP

// include
# include <string>
# include <iostream>
# include "Weapon.hpp"

// macro

// class
class HumanA
{
	public:
		void attack();
		HumanA(std::string str,Weapon &wep);
	private:
		std::string name;
		Weapon& bring_wep;
};

#endif