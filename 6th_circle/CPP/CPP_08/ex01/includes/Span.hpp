/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:30:17 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/22 03:28:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "sio.hpp"
# include <set>
# include <limits>
# include <cstdlib>
# include <ctime>
# include <vector>

//subject
class Span
{
	public:
		//canonical
		~Span();
		Span(const Span& cp);
		Span& operator=(const Span& cp);

		//this subject
		Span(unsigned int N);
		unsigned int getSize() const;
		std::multiset<int> getmSet() const;
		void addNumber(int n);
		void addRandomNumber(int addnum, unsigned int limit);
		template<typename Ite>
		void addNumber(Ite begin, Ite end)
		{
			unsigned int adsize = std::distance(begin,end);
			if(this->_nowsize + adsize > this->_maxsize)
				throw Span::fullSet();
			this->_mset.insert(begin,end);
			this->_nowsize += adsize;
		}
		int shortestSpan( void ) const;
		int longestSpan( void ) const;

		class noSpan : public std::exception
		{
			const char* what() const throw();
		};

		class fullSet : public std::exception
		{
			const char* what() const throw();
		};

		std::string strMyClass() const;
		
	private:
		Span(); // cant use but canonical form
		const unsigned int _maxsize;
		unsigned int _nowsize;
		std::multiset<int> _mset;
};


#endif
