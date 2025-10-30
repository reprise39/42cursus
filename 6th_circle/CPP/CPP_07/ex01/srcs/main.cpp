/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:05:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/30 11:28:33 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// in subject main
int main(void)
{
	// int
	std::cout << "\n== int test ==" <<  std::endl;
	int dvec[] = {1, 2, 3, 4, 5};

	::iter(dvec, 5, ::print);
	std::cout << std::endl;

	::iter(dvec, 3, ::dbl);
	
	::iter(dvec, 5, ::print);
	std::cout << std::endl;

	// const int
	std::cout << "\n== const int test ==" <<  std::endl;
	const int cdvec[] = {1, 2, 3, 4, 5};

	::iter(cdvec, 5, ::print);
	std::cout << std::endl;

	// float
	std::cout << "\n== float test ==" <<  std::endl;
	float fvec[] = {1.1, 2.0, 3.3, 4.4, 5.0};

	::iter(fvec, 5, ::print);
	std::cout << std::endl;

	::iter(fvec, 4, ::dbl);
	
	::iter(fvec, 5, ::print);
	std::cout << std::endl;

	return (0);
}
