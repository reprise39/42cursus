/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:24:03 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 19:24:03 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

// include
# include "sio.hpp"

// macro

// class
class Animal
{
	public:
		Animal();
		Animal(const std::string& str);
		Animal(const Animal& c);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		std::string printMyClass() const;
		virtual void makeSound() const;

		std::string getType() const;
		void setType(const std::string& str);

	protected:
		std::string _Type;
};

#endif