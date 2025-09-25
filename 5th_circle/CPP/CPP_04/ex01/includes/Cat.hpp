/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:10:52 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 12:15:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string &str);
		Cat(const Cat &c);
		~Cat();
		
		Cat& operator=(const Cat &other);
		
		void makeSound() const;
		void makeIdea(const int n,const std::string& str) const;
		std::string getIdea(const int n) const;
		std::string printMyClass() const;
	
	private:
		Brain*	_MyBrain;
};

#endif