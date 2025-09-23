/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:54:19 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/21 12:54:19 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

// include
# include <iostream>
# include <string> 

// macro

// class
class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string& str);
		ClapTrap(const ClapTrap& c);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

		virtual std::string printMyClass() const ;

		void setName( const std::string& str );
		void setHP( int amount );
		void setEP( int amount );
		void setAD( int amount );

		const std::string& getName() const;
		int getHP() const;
		int getEP() const;
		int getAD() const;

	private:
		std::string _Name;
		int _Hitpoint;
		int _EnergyPoint;
		int _AttackDamage;
};

std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& reset(std::ostream& os);

#endif