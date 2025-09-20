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
# include <iostream>
# include <cmath>

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

		//operatir
		Fixed& operator=(const Fixed& other);
	private:
		int _fp_n;
		static const int _fractional_bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif