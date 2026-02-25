/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:09:34 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/25 17:29:05 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


static int is_valit_date(std::string str, std::tm* now) //yyyy/mm/dd
{
	std::istringstream iss(str);
	int y, m , d;
	char sep1, sep2;
	std::string nostr;
	
	iss >> y >> sep1 >> m >> sep2 >> d >> nostr;
	// std::cout << y << m << d;

	if (sep1 != '-' || sep2 != '-')
		return (1);

	//
	std::tm time = std::tm();
	time.tm_year = y - 1900;
	time.tm_mon = m - 1;
	time.tm_mday = d;
		
	std::time_t itimet = std::mktime(&time);
	std::time_t ntimet = std::mktime(now);

	if( itimet == -1 || ntimet == -1)
	{
		std::cout << red << "cant cast time_t" << reset << std::endl;
		return (1);		
	}
	if(ntimet < itimet)
	{
		std::cout << red << "future date" << reset << std::endl;
		return (1);		
	}
	if(time.tm_year != y-1900 || time.tm_mon != m-1 || time.tm_mday != d)
	{
		std::cout << red << "un-exist date" << reset << std::endl;
		return (1);
	}
	if (nostr.length() == 0)
	{
		return (0);
	}
	else
	{
		std::cout << red << "extra-word exist = " << str << reset << std::endl;
		return (1);
	}
}

static int is_valit_rate(std::string rate)
{
	std::istringstream iss(rate);
	double d;
	std::string nostr;

	iss >> d >> nostr;
	if(d < 0 )
	{
		std::cout << "not a positive number." << std::endl;
		return (1);
	}
	if(d > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (1);
	}
	if(nostr.length() == 0)
		return (0);
	else
	{
		std::cout << blue << "Error: bad input => " << rate << reset << std::endl;
		return (1);
	}
}

static double my_stod(std::string rate)
{
	std::istringstream iss(rate);
	double d;

	iss >> d;
	return (d);
}

static int appendDB(std::string& line, std::map<std::string, double>& rate_db, std::tm* now)
{
	std::cout << "======== <appendDB> ========\n" << std::endl;

	// check only space
	unsigned int line_pos = 0;
	while (line[line_pos] == " " && line_pos < line.size())
		line_size++;
	if (line.size() == line_pos)
		retrun (0);
	
	std::string::size_type pos = 0;
	//date
	pos = line.find(',', pos);
	std::string date = line.substr(0,pos);
	if( pos == std::string::npos || is_valit_date(date,now) != 0 )
	{
		std::cout << red << "break-appendDB : no',' or invalid-date" << reset << std::endl;
		std::cout << red << "prease check data.csv" << reset << std::endl;
		return 1;
	}

	++pos;
	//value
	std::string::size_type newpos = line.find(',', pos);
	std::string rate = line.substr(pos);
	if( newpos != std::string::npos || is_valit_rate(rate) != 0 )
		return ;
	std::cout << "date = " << date << ", rate =" << rate << std::endl;
	std::cout << "======== <endDB> ========\n" << std::endl;
	rate_db[date] = my_stod(rate);
	return (0);
}

double getprice(const std::string& date,const std::map<std::string ,double>& rate_db)
{
	auto it = rate_db.begin();
	std::string ans = it->first;
	it++;
	while((it->first) < ans && it != rate_db.begin())
	{
		ans = it->first;
		it++;
	}
	return ((--it)->second);
}

static bool is_blank(const std::string &str)
{
	for(size_t i = 0 ; i < str.size() ; ++i)
	{
		if(!isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}


void printansline(std::string line, std::map<std::string, double> &rate_db, std::tm* now)
{
	if(is_blank(line))
		return ;
	std::string::size_type pos = 0;
	pos = line.find('|', pos);
	std::string date = line.substr(0,pos);
	if( pos == std::string::npos || is_valit_date(date,now) != 0 )
	{
		std::cout << blue << "Error: bad input => " << date << reset << std::endl;
		return ;
	}
	++pos;
	//value
	std::string::size_type newpos = line.find('|', pos);
	std::string rate = line.substr(pos);
	if( newpos != std::string::npos || is_valit_rate(rate) != 0 )
		return ;
	double nm = my_stod(rate);
	double price = getprice(date,rate_db);
	std::cout << date << " => " << nm << " = " << (price*nm) << std::endl;
}


void printans(std::map<std::string, double> &rate_db, std::tm* now)
{
	std::ifstream ifs;
	ifs.open(IFNAME);
	std::istringstream iss;

	while(ifs)
	{
		std::string line;
		std::getline(ifs,line);
		if(line.size() > 0)
			printansline(line,rate_db, now);
	}
}

void makeDB(std::map<std::string, double>& db)
{
	std::ifstream file;
	std::time_t t = std::time(NULL);
	std::tm* now = localtime(&t);
	
	file.open("data.csv");
	while(file)
	{
		std::string line;
		std::getline(file, line);
		if (appendDB(line,db,now) == 1)
			return (1);
	}
	
	for(auto it = db.begin(); it != db.end(); ++it)
	{
		std::cout << "key: " << it->first 
		<< ",  value: " << it->second << std::endl;
	}

	printans(rate_db,now);
}
