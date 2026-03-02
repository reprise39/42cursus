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

// private utils

static bool is_blank(const std::string &str)
{
	for(size_t i = 0 ; i < str.size() ; ++i)
	{
		if(!isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

static int is_file(const char* fname)
{
	std::ifstream rdfile;
	rdfile.open(fname);

	if(!rdfile.is_open())
		return (1);
	rdfile.close();
	return (0);
}


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

// canonical form

BitcoinExchanger::BitcoinExchanger()
{
	std::cout << green << "Constructor called" << reset << std::endl;
}

BitcoinExchanger::BitcoinExchanger(char* arg) : _mode(DEV_MODE), _t(std::time(NULL)), _now(localtime(&_t))
{
	std::cout << green << "Constructor called" << reset << std::endl;

	if (arg == NULL)
		throw BitcoinExchanger::Error("Error: no arg");
	if(is_file(arg) != 0)
		throw Error("arg1-file (according to bitocoin date-amount) cant open\n");
	if(is_file(CSV_DB_NAME) != 0)
		throw Error("input-file (data.csv according to bitocoin date-rate) cant open\n");

	this->_ifname = arg;
	this->_makeDB();
}


BitcoinExchanger::~BitcoinExchanger()
{
	std::cout << red << "Destructor called" << reset << std::endl;
}


BitcoinExchanger::BitcoinExchanger(const BitcoinExchanger& other)
{
	std::cout << green << "Copy Constructor called" << reset << std::endl;
	*this = other;
}

BitcoinExchanger& BitcoinExchanger::operator=(const BitcoinExchanger& other)
{
	if (this != &other)
	{
		this->_rate_db = other._rate_db;
		this->_ifname = other._ifname;
		this->_t = other._t;
		this->_now = other._now;
		this->_mode = other._mode;
	}
	return (*this);
}


// exception
const char* BitcoinExchanger::Error::what() const throw()
{
	return (this->_msg);
}


// main-function

void BitcoinExchanger::_appendDB(std::string& line)
{
	// std:: cout << line << std::endl;
	if (this->_mode == DEBAG_MODE)
		std::cout << green << "======== <appendDB> ========\n" << reset << std::endl;

	// check only space
	unsigned int line_pos = 0;
	while (line[line_pos] == ' ' && line_pos < line.size())
		line_pos++;
	if (line.size() == line_pos)
		return ;
	
	// date
	std::string::size_type pos = 0;
	pos = line.find(',', pos);
	std::string date = line.substr(0,pos);
	if( pos == std::string::npos || is_valit_date(date, this->_now) != 0 )
		throw BitcoinExchanger::Error("Error: rate_db has invalid-date");
	++pos;
	//value
	std::string::size_type newpos = line.find(',', pos);
	std::string rate = line.substr(pos);
	if( newpos != std::string::npos || is_valit_rate(rate) != 0 )
		throw BitcoinExchanger::Error("Error: rate_db has invalid-value");
	if( this->_mode == DEBAG_MODE)
	{
		std::cout << "date = " << date << ", rate =" << rate << std::endl;
		std::cout << green << "======== <endDB> ========\n" << reset << std::endl;			
	}
	this->_rate_db[date] = my_stod(rate); // can override
}

void BitcoinExchanger::_makeDB()
{
	std::ifstream file;
	
	file.open(CSV_DB_NAME);
	size_t i = 0;
	while(file)
	{
		std::string line;
		std::getline(file, line);
		if(i != 0)
			_appendDB(line);
		i++;
	}
	
	if(this->_mode == DEBAG_MODE)
	{
		for(auto it = this->_rate_db.begin(); it != this->_rate_db.end(); ++it)
		{
			std::cout << "key: " << it->first 
			<< ",  value: " << it->second << std::endl;
		}
	}
}

void BitcoinExchanger::_printansline(std::string line)
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
	if( is_valit_date(date,this->_now) != 0 )
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
	double price = _getprice(date);
	std::cout << date << " => " << nm << " = " << (price*nm) << std::endl;
}


void BitcoinExchanger::print()
{
	if(this->_mode == DEBAG_MODE)
		std::cout << green << "<< start printans >>" << reset << std::endl;
	
	std::ifstream txt_file;
	txt_file.open(this->_ifname);
	size_t col = 0;
	while(txt_file)
	{
		std::string line;
		std::getline(txt_file, line);
		if(col != 0)
		{
			if ( line.size() != 0 )
				_printansline(line);
		}
		col++;
	}
	if(_mode == DEBAG_MODE)
		std::cout << green << "<< end printans >>" << reset << std::endl;
}

double BitcoinExchanger::_getprice(const std::string& date)
{
	auto it = this->_rate_db.begin();
	std::string ans = it->first;
	while((it->first) <= date && it != this->_rate_db.end())
		it++;

	if(it != this->_rate_db.begin())
		it--;
	return ((it)->second);
}
