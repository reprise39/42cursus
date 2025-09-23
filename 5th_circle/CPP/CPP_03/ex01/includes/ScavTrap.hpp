/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:00:42 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/23 02:39:40 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# ifndef CLAPTRAP_HPP
#  include "ClapTrap.hpp"
#  define CLAPTRAP_HPP
# endif

class ScavTrap : private ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string& str);
		~ScavTrap();
		void guardGate();

	private:
		bool _isGardMord;
};


#endif