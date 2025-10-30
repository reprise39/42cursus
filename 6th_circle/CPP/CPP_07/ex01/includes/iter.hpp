/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:30:17 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/30 11:36:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

//subject
template<typename T>
void dbl(T &i)
{
	i = i*2;
}

template<typename T>
void print(const T &t)
{
	std::cout << t << " : ";
}

template<typename T>
void iter(T a[], size_t d, void (*func)(T&))
{
	for(size_t i = 0; i < d ; i++)
		func(a[i]);
}

template<typename T>
void iter(const T *a, size_t len, void (*func)(const T&))
{
	for(size_t i = 0; i < len ; i++)
		func(a[i]);
}

//for bog data : type using ref



#endif
