/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:47:19 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:41:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTOR_HPP
# define ICHARACTOR_HPP

// include
# include "sio.hpp"

class AMateria; //

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif