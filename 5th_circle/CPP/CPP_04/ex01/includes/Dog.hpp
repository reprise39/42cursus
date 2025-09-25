/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:10:52 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/25 12:16:06 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string &str);
		Dog(const Dog &c);
		~Dog();
		
		Dog& operator=(const Dog &other);
		
		void makeSound() const;
		void makeIdea(const int n,const std::string& str) const;
		std::string getIdea(const int n) const;
		std::string printMyClass() const;
	
	private:
		Brain* _MyBrain;
};

#endif