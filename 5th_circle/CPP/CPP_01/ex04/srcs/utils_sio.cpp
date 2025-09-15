/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrck_arg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:07:48 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/24 13:07:48 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::ostream& red(std::ostream& os)
{
	return os << "\033[31m";
}
std::ostream& blue(std::ostream& os)
{
	return os << "\033[34m";
}
std::ostream& reset(std::ostream& os)
{
	return os << "\033[0m";
}
