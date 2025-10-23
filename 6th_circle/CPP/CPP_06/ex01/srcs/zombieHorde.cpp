/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:25:22 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/11 20:25:22 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *dest;
	dest = new Zombie[N];
	for ( int i = 0 ; i < N ; i++)
	{
		dest[i].setname(name);
		dest[i].announce();
	}
	return (dest);
}
