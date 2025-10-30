/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sio.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:27:35 by mkuida            #+#    #+#             */
/*   Updated: 2025/10/29 21:13:15 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIO_HPP
# define SIO_HPP

# include <iostream>
# include <string>
# include <sstream>

std::ostream& red(std::ostream& os);
std::ostream& yellow(std::ostream& os);
std::ostream& blue(std::ostream& os);

std::ostream& reset(std::ostream& os);

std::string strConstMsg();
std::string strDestMsg();

#endif
