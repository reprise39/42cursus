/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:07:07 by mkuida            #+#    #+#             */
/*   Updated: 2026/03/21 18:03:59 by mkuida           ###   ########.fr       */
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

#define CSV_DB_NAME "data.csv"
#define IFNAME "input.csv"
#define DEV_MODE 0
#define DEBAG_MODE 1

class BitcoinExchanger
{
	public:
		BitcoinExchanger(char* arg);
		~BitcoinExchanger();
		BitcoinExchanger(const BitcoinExchanger& other);
		BitcoinExchanger& operator=(const BitcoinExchanger& other);


		void print();
		
		class Error : public std::exception
		{
			public:
				Error(const char* msg) : _msg(msg) {}
				const char* what() const throw();

			private:
				const char* _msg;
		};

	private:
		BitcoinExchanger();

		std::map<std::string, double> _rate_db;
		char* _ifname;
		int _mode;
		time_t _t;
		tm* _now;

		void _appendDB(std::string& line);
		void _makeDB();
		void _printansline(std::string line);
		double _getprice(const std::string& date);
};