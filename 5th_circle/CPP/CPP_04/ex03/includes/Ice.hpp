/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:49:49 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:02:37 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

// include
# include "AMateria.hpp"

class Ice : public AMateria
{
	protected:
		//

	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const AMateria& other);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
		std::string printMyClass() const;
};

#endif