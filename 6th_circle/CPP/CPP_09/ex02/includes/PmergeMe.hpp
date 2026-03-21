/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PergeMe.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:24:03 by mkuida            #+#    #+#             */
/*   Updated: 2026/03/21 19:41:44 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERGEME_HPP
# define PERGEME_HPP

// include
# include <string>
# include <deque>
# include <vector>
# include <ctime>
# include <unistd.h> // for usleep
# include <iostream>

// macro
#define RESERVE_MODE 1


// class
class PergeMe
{
	public:
		PergeMe(std::vector<int>myvec, std::deque<int> mydeq);
		~PergeMe(){};
		PergeMe(const PergeMe& other);
		PergeMe& operator=(const PergeMe& other);

		void printAns() const;
		std::string vec_to_str() const;

		class input_error : public std::exception
		{
			public:
				input_error(const char* msg) : _msg(msg) {}
				const char* what() const throw();
			private:
				const char* _msg;
		};

	protected:
		PergeMe(){};

		std::vector<int> _vecint;
		std::deque<int> _deqint;
		unsigned int _vectime;
		unsigned int _deqtime;
		unsigned int _range;
		std::string _input;
		std::string _ans;

		void _mergeInsertSortVec();
		void _mergeInsertSortDeq();
};

std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& reset(std::ostream& os);

#endif

