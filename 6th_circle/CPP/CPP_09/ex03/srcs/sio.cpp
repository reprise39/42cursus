/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sio.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:19:22 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 16:28:21 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sio.hpp"

std::ostream& red(std::ostream& os)
{
	return (os << "\033[31m");
}

std::ostream& blue(std::ostream& os)
{
	return (os << "\033[34m");
}

std::ostream& yellow(std::ostream& os)
{
	return (os << "\033[33m");
}

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}
