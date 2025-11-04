/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:30:17 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/31 19:29:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// include lib
# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

// the subject
// template<typename T>
// typename T[]::iterator easyfind(T target, const T& array[])
// {
// 	T[]::iterator bgn = array.begin();
// 	T[]::iterator end = array.end();

// 	for(T::iterator now = bgn ; bgn < end ; bgn++)
// 	{
// 		if(array[now] == target)
// 			return (now);
// 	}
// }

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}

#endif
