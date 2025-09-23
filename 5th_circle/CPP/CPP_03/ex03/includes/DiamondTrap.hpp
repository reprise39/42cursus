/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:51:56 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 00:55:17 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FlagTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FlagTrap, ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string& str);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();
		
		void WhoAmI();
		std::string printMyClass() const;

		DiamondTrap& operator=(const DiamondTrap& other);

	private:
		std::string _Name;
};



#endif