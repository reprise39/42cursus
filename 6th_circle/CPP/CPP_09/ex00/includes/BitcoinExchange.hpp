/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:07:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/11/07 17:53:15 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include "sio.hpp"

#define IFNAME "input.csv"

void makeDB(std::map<std::string, double>& rate_db, const char* filename);