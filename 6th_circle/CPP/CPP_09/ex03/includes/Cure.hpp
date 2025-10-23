/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:49:26 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 14:02:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

// include
# include "AMateria.hpp"

class Cure : public AMateria
{
	protected:
		//[...]

	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const AMateria& other);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
		std::string printMyClass() const;
};

#endif