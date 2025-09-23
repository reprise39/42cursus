/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:00:42 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 00:56:42 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& str);
		ScavTrap(const ScavTrap& c);
		~ScavTrap();
		void guardGate();

		ScavTrap&  operator=(const ScavTrap& other);

		std::string printMyClass() const;

		void setActiveGg();
		void setNegativeGg();

		bool getGg() const ;

	private:
		bool _isGardMord;
};


#endif