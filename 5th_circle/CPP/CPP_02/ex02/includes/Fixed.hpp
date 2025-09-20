/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phonbook.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:43:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/09 17:43:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

// include
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdio>
# include <sstream>
#include  <cmath>

// macro

// class
class Fixed
{
	public:

		//structor
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& c);
		~Fixed();

		//function
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);

		//operatir
		Fixed& operator=(const Fixed& other);
		Fixed operator+(const Fixed& other) const ;
		Fixed operator-(const Fixed& other) const ;
		Fixed operator*(const Fixed& other) const ;
		Fixed operator/(const Fixed& other) const ;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		bool operator<(const Fixed& other) const ;
		bool operator>(const Fixed& other) const ;
		bool operator<=(const Fixed& other) const ;
		bool operator>=(const Fixed& other) const ;
		bool operator==(const Fixed& other) const ;
		bool operator!=(const Fixed& other) const ;

		private:
		int _fp_n;
		static const int _fractional_bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

// xxx.cpp
std::ostream& reset(std::ostream& os);
std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& yellow(std::ostream& os);

#endif