/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phonbook.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:43:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:43:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ZOMBIE_HPP
# define FT_ZOMBIE_HPP

// include
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdio>
# include <sstream>

// macro

// class
class Zombie
{
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void announce(void);
		void setname(std::string name);
	private:
		std::string name;
};

// newZombie.cpp
Zombie* newZombie(std::string name );

// ramdomChump.cpp
void randomChump(std::string name);

// zombieHorde.cpp
Zombie* zombieHorde( int N, std::string name );

#endif