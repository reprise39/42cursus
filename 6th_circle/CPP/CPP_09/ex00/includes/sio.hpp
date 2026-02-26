/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sio.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:27:35 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/26 13:00:46 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIO_HPP
# define SIO_HPP

# include <iostream>

std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& green(std::ostream& os);
std::ostream& reset(std::ostream& os);

#endif