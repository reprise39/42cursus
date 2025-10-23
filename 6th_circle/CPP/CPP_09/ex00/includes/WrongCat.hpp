/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:10:52 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 10:25:47 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string &str);
		WrongCat(const WrongCat &c);
		~WrongCat();
		
		WrongCat& operator=(const WrongCat &other);
		
		void makeSound() const;
		
		std::string printMyClass() const;
	
	private:

};

#endif