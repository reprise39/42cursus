/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:39:52 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 15:47:51 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIAL_HPP
# define AMATERIAL_HPP

// include
# include "sio.hpp"
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		//[...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		std::string printMyClass() const;
};

#endif