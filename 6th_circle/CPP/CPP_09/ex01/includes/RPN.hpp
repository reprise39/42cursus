/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:36:29 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/25 19:13:01 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "sio.hpp"
# include <stack>
# include <string>
# include <cstdlib>
# include <iostream>

// void cal(char* argv);
bool is_my_digit(char argv);
bool is_my_operator(char argv);
bool is_my_brank(char argv);

void cal(char* argv);

#endif