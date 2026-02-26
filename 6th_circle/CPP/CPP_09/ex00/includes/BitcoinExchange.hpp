/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:07:07 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/26 11:11:13 by mkuida           ###   ########.fr       */
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

void makeDB(std::map<std::string, double>& rate_db);
void printans(char* arg, std::map<std::string, double>& db);