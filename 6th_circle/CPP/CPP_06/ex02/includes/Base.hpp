/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:21:02 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/28 13:10:57 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include "sio.hpp"
#include <stdlib.h>

class Base
{
	public :
		Base();
		virtual ~Base();
};

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//subject
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif