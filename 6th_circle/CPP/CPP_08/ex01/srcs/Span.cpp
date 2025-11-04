/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:14:15 by mkuida            #+#    #+#             */
/*   Updated: 2025/11/04 11:24:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() : _maxsize(0), _nowsize(0), _mset()
{
	std::cout << blue
			  << strMyClass() << "Defo-" << strConstMsg() << reset << std::endl;
}

Span::Span(unsigned int N) : _maxsize(N), _nowsize(0), _mset()
{
	std::cout << blue
			  << strMyClass() << "Defo-" << strConstMsg() << reset << std::endl;
}

Span::Span(const Span& cp) : _maxsize(cp.getSize())
{
	*this = cp;
		
	std::cout << blue
		<< strMyClass() << "Copy-" << strConstMsg() << reset << std::endl;
}

Span::~Span()
{
	std::cout << red
			  << strMyClass() << "Defo-" << strDestMsg() << reset << std::endl;
}

Span& Span::operator=(const Span& cp)
{
	if(this != &cp)
	{
		this->_nowsize = cp.getSize();
		this->_mset = cp.getmSet();
	}
	return (*this);
}

//this subject
unsigned int Span::getSize() const
{
	return(this->_maxsize);
}

std::multiset<int> Span::getmSet() const
{
	return(this->_mset);
}

void Span::addNumber(int n)
{
	if((this->_nowsize) + 1 > (this->_maxsize))
		throw(Span::fullSet());
	this->_mset.insert(n);
	this->_nowsize++;
}

int Span::shortestSpan( void ) const
{
	if(this->_mset.size() < 2)
		throw(Span::noSpan());

	int ans = std::numeric_limits<int>::max();
	std::multiset<int>::const_iterator sIter = this->_mset.begin();
	std::multiset<int>::const_iterator nIter = ++(this->_mset.begin());
	std::multiset<int>::const_iterator eIter = this->_mset.end();

	while(nIter != eIter)
	{
		// std::cout << *nIter << "-" << *sIter << "compare" << std::endl;
		ans = std::min(ans, *nIter - *sIter);
		++sIter;
		++nIter;
	}
	return (ans);
}

int Span::longestSpan( void ) const
{
	if(this->_mset.size() < 2)
		throw(Span::noSpan());

	std::multiset<int>::const_iterator sIter = this->_mset.begin();
	std::multiset<int>::const_iterator eIter = --(this->_mset.end());

	return (*eIter - *sIter);
}


std::string Span::strMyClass() const
{
	return ("<class : Span> ");
}

const char* Span::noSpan::what() const throw()
{
	return ("< too less integer > cant calculate span");
}

const char* Span::fullSet::what() const throw()
{
	return ("< this class is already full > cant add containts");
}
