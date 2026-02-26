/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sio.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:19:22 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/26 13:01:21 by mkuida           ###   ########.fr       */
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

std::ostream& green(std::ostream& os)
{
	return (os << "\033[32m");
}

std::ostream& reset(std::ostream& os)
{
	return (os << "\033[0m");
}
