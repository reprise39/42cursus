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

// macro

// class
class Fixed
{
	public:
		Fixed();
		Fixed(Fixed& c);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int fp_n;
		static const int fractional_bit = 8;
};

// xxx.cpp


#endif