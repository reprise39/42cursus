/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:10:52 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 10:25:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string &str);
		Cat(const Cat &c);
		~Cat();
		
		Cat& operator=(const Cat &other);
		
		void makeSound() const;
		
		std::string printMyClass() const;
	
	private:

};

#endif