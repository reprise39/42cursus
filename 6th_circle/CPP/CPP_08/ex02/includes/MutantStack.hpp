/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:09:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/11/04 12:09:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

// include
#include "sio.hpp"

//assert
#include <stack>
#include <deque>
#include <algorithm>

// macro

// class
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::iterator const_iterator;

		//non-const
		typename std::stack<T>::container_type::iterator begin()
			{return (this->c.begin());}
		typename std::stack<T>::container_type::iterator end()
			{return (this->c.end());}

		//const
		typename std::stack<T>::container_type::const_iterator begin() const
			{return (this->c.begin());}
		typename std::stack<T>::container_type::const_iterator end() const
			{return (this->c.end());}
};

#endif