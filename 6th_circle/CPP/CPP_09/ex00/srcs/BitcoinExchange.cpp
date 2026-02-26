/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:09:34 by mkuida            #+#    #+#             */
/*   Updated: 2026/02/26 13:06:12 by mkuida           ###   ########.fr       */
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
		std::cout << red << "Error (data.csv) : negative number is not allow" << reset << std::endl;
		return (1);
	}
	if(nostr.length() == 0)
		return (0);
	else
	{
		std::cout << red << "Error (data.csv) : bad input => " << rate << reset << std::endl;
		return (1);
	}
}

static int is_valit_value(std::string rate)
{
	std::istringstream iss(rate);
	double d;
	std::string nostr;

	iss >> d >> nostr;
	if(d < 0 )
		return (-1);
	if(d > 1000)
		return (1);
	if(nostr.length() == 0)
		return (0);
	else
		return (2);
}

static double my_stod(std::string rate)
{
	std::istringstream iss(rate);
	double d;

	iss >> d;
	return (d);
}

static int appendDB(std::string& line, std::map<std::string, double>& rate_db, std::tm* now, int mode)
{
	if (mode == DEBAG_MODE)
		std::cout << green << "======== <appendDB> ========\n" << reset << std::endl;

	// check only space
	unsigned int line_pos = 0;
	while (line[line_pos] == ' ' && line_pos < line.size())
		line_pos++;
	if (line.size() == line_pos)
		return (0);
	
	// date
	std::string::size_type pos = 0;
	pos = line.find(',', pos);
	std::string date = line.substr(0,pos);
	if( pos == std::string::npos || is_valit_date(date,now) != 0 )
	{
		std::cout << red << "Error (data.csv) : break-appendDB  no',' or invalid-date" << reset << std::endl;
		return (1);
	}

	++pos;
	//value
	std::string::size_type newpos = line.find(',', pos);
	std::string rate = line.substr(pos);
	if( newpos != std::string::npos || is_valit_rate(rate) != 0 )
		return (1); // need check
	if( mode == DEBAG_MODE)
	{
		std::cout << "date = " << date << ", rate =" << rate << std::endl;
		std::cout << green << "======== <endDB> ========\n" << reset << std::endl;			
	}
	rate_db[date] = my_stod(rate); // can override
	return (0);
}

double getprice(const std::string& date,const std::map<std::string ,double>& rate_db)
{
	auto it = rate_db.begin();
	std::string ans = it->first;
	while((it->first) <= date && it != rate_db.end())
		it++;

	if(it != rate_db.begin())
		it--;
	return ((it)->second);
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
	if( pos == std::string::npos )
	{
		std::cout << blue << "Error: bad input => " << line << reset << std::endl;
		return ;
	}
	if( is_valit_date(date,now) != 0 )
	{
		std::cout << blue << "Error: uncorrect-date => " << date << reset << std::endl;
		return ;
	}

	++pos;
	//value
	std::string::size_type newpos = line.find('|', pos);
	std::string value = line.substr(pos);
	int checkvalue_rtn = is_valit_value(value);
	if ( checkvalue_rtn == -1)
	{
		std::cout << blue << "Error: not a positive number." << reset << std::endl;
		return ;
	}
	if ( checkvalue_rtn == 1)
	{
		std::cout << blue << "Error: too large a number." << reset << std::endl;
		return ;
	}
	if ( checkvalue_rtn == 2)
	{
		std::cout << blue << "data.csv Error : bad input => " << line << reset << std::endl;
		return ;
	}
	//cal
	double nm = my_stod(value);
	double price = getprice(date,rate_db);
	std::cout << date << " => " << nm << " = " << (price*nm) << std::endl;
}


void printans(char* arg, std::map<std::string, double>& db, int mode)
{
	std::ifstream txt_file;
	txt_file.open(arg);
	std::istringstream iss;

	std::time_t t = std::time(NULL);
	std::tm* now = localtime(&t);

	if(mode == DEBAG_MODE)
		std::cout << green << "<< start printans >>" << reset << std::endl;
	
	size_t col = 0;
	while(txt_file)
	{
		std::string line;
		std::getline(txt_file, line);
		if(col != 0)
		{
			if ( line.size() != 0 )
				printansline(line, db, now);
		}
		col++;
	}
	if(mode == DEBAG_MODE)
		std::cout << green << "<< end printans >>" << reset << std::endl;
}

void makeDB(std::map<std::string, double>& db, int mode)
{
	std::ifstream file;
	std::time_t t = std::time(NULL);
	std::tm* now = localtime(&t);
	
	file.open("data.csv");
	size_t i = 0;
	while(file)
	{
		std::string line;
		std::getline(file, line);
		if(i != 0)
		{
			if ( appendDB(line, db, now, mode) == 1 )
				exit (1);
		}
		i++;
	}
	
	if(mode == DEBAG_MODE)
	{
		for(auto it = db.begin(); it != db.end(); ++it)
		{
			std::cout << "key: " << it->first 
			<< ",  value: " << it->second << std::endl;
		}
	}
}
