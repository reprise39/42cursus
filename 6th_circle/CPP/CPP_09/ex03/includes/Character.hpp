/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:05:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 16:06:27 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// include
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	
	public:
		Character();
		Character(std::string const & name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();
	
		// ICharacter implementation
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		std::string printMyClass() const;
};

#endif