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
		Fixed();
		Fixed(const Fixed& c);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _fp_n;
		static const int _fractional_bit = 8;
};

#endif