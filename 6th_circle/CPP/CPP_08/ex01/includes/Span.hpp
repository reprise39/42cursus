/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:30:17 by mkuida            #+#    #+#             */
/*   Updated: 2025/11/04 11:23:13 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "sio.hpp"
# include <set>
# include <limits>
# include <cstdlib>
# include <ctime>

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
