/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:06:51 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 00:56:36 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
	public:
		FlagTrap();
		FlagTrap(const std::string& str);
		FlagTrap(const FlagTrap& c);
		~FlagTrap();

		FlagTrap&  operator=(const FlagTrap& other);

		std::string printMyClass() const;
		void highFivesGuys(void);

	private:

};


#endif