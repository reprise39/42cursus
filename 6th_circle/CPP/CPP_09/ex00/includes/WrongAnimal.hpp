/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:24:03 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 19:24:03 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

// include
# include "sio.hpp"

// macro

// class
class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const std::string& str);
		WrongAnimal(const WrongAnimal& c);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		std::string printMyClass() const;
		void makeSound() const;

		std::string getType() const;
		void setType(const std::string& str);

	protected:
		std::string _Type;
};

#endif