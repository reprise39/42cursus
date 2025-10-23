/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sio.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:27:35 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/26 16:26:08 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIO_HPP
# define SIO_HPP

# include <iostream>
# include <string>

std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& yellow(std::ostream& os);
std::ostream& reset(std::ostream& os);

#endif