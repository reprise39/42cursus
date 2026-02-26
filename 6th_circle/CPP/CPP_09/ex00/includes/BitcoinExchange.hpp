/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:07:07 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/26 12:57:55 by mkuida           ###   ########.fr       */
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
#define DEV_MODE 0
#define DEBAG_MODE 1



void makeDB(std::map<std::string, double>& rate_db, int mode);
void printans(char* arg, std::map<std::string, double>& db, int mode);