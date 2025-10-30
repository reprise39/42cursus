/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:30:17 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/30 11:08:10 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

//subject
template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//for bog data : type using ref
template<typename T>
const T &min(const T &a, const T &b)
{
	if(b > a)
		return (a);
	return (b);
}

template<typename T>
const T &max(const T &a, const T &b)
{
	if(a > b)
		return (a);
	return (b);
}

#endif
