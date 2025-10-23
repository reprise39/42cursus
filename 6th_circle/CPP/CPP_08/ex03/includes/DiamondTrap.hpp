/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:51:56 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 20:53:11 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string& str);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();
		
		void whoAmI();
		std::string printMyClass() const;

		DiamondTrap& operator=(const DiamondTrap& other);

	private:
		std::string _Name;
};



#endif