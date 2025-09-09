/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_Account.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:27:21 by mkuida            #+#    #+#             */
/*   Updated: 2025/09/09 19:58:36 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

//initialize
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//public
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);	
}
int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);	
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

	//constracta
Account::Account( int initial_deposit )
{
		this->_accountIndex = getNbAccounts();
		_nbAccounts++;
		
		this->_amount = initial_deposit;
		_totalAmount += initial_deposit;
		
		this->_nbDeposits = 0;
		this->_nbWithdrawals = 0;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

	//destract
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit;

	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;

	std::cout << ";amount:" << checkAmount() << ";nb_deposits:" << (this->_nbDeposits) << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount();
	
	if(checkAmount() < withdrawal )
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
	
//private
void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm* printtime = std::localtime(&now);
	
	char buf[20] = {}; //min ha 15
	if (std::strftime(buf, sizeof(buf) ,"[%Y%m%d_%H%M%S] " , printtime) != 0)
	{
		std::cout << buf;
	}
}
