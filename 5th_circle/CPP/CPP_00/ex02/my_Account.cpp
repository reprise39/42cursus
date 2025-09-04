/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_Account.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:27:21 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/03 18:55:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

//constracta
Account::Account( int initial_deposit )
{
	// this->_nbAccounts;
	// this->_totalAmount;
	// this->_totalNbDeposits;
	// this->_totalNbWithdrawals;
	
	this->_accountIndex = 0; // tigau
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";created" << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm* printtime = std::localtime(&now);
	
	char buf[20] = {}; //min ha 15
	if (std::strftime(buf, sizeof(buf) ,"[%Y%m%d%H%M%S] " , printtime) != 0)
	{
		std::cout << buf;
	}
}
