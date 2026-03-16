/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:24:03 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/24 19:24:03 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERGEME_HPP
# define PERGEME_HPP

// include
# include <deque>
# include <vector>
# include <iostream>
# include <sstream>
# include <ctime>
# include "sio.hpp"

// macro

// class
class PergeMe
{
	public:
		PergeMe(std::vector<int>myvec, std::deque<int> mydeq);
		~PergeMe();
		PergeMe(const PergeMe& other);
		PergeMe& operator=(const PergeMe& other);

		void printAns() const;

		class input_error : public std::exception
		{
			public:
				input_error(const char* msg) : _msg(msg) {}
				const char* what() const throw();
			private:
				const char* _msg;
		};

	protected:
		PergeMe();

		std::vector<int> _vecint;
		std::deque<int> _deqint;
		unsigned int _vectime;
		unsigned int _deqtime;
		unsigned int _range;
		std::string _input;
		std::string _ans;
};

#endif