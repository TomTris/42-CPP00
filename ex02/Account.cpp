/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:04:56 by qdo               #+#    #+#             */
/*   Updated: 2024/05/26 04:07:18 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

#define BLUE "\x1b[34m"
#define WHITE "\x1b[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(nullptr);
	std::tm*	localTime = std::localtime(&now);
	
	std::cout << "[" << localTime->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << localTime->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << localTime->tm_hour
		<< std::setw(2) << std::setfill('0') << localTime->tm_min
		<< std::setw(2) << std::setfill('0') << localTime->tm_sec<< "] "
		<< std::ends;
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE
			  << ";amount:" << BLUE << _amount << WHITE
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE
			  << ";amount:" << BLUE << _amount << WHITE
			  << ";closed" << std::endl;
}

int Account::getNbAccounts(void)			{return (_nbAccounts);}
int	Account::getTotalAmount(void)			{return (_totalAmount);}
int	Account::getNbDeposits(void) 			{return (_totalNbDeposits);}
int	Account::getNbWithdrawals(void) 		{return (_totalNbWithdrawals);}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << BLUE << _nbAccounts << WHITE
			  << ";total:" << BLUE << _totalAmount << WHITE
			  << ";deposits:" << BLUE << _totalNbDeposits << WHITE
			  << ";withdrawals:" << BLUE << _totalNbWithdrawals << WHITE
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE
			  << ";p_amount:" << BLUE << _amount << WHITE
			  <<";deposit:" << BLUE << deposit << WHITE;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << BLUE << _amount << WHITE
			  << ";nb_deposists" << BLUE << _nbDeposits << WHITE
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE
			  << ";p_amount:" << BLUE << _amount << WHITE;
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << BLUE << withdrawal << WHITE
				  << ":amount" << BLUE << _amount << WHITE
				  << ";nb_withdrawals:" << BLUE << _nbWithdrawals << WHITE
				  << std::endl;
		return (true);
	}
	std::cout << ";withdrawal:" << "refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const	{return (_amount);}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE
			  << ";amount" << BLUE << _amount << WHITE
			  << ";deposits:" << BLUE << _nbDeposits << WHITE
			  << ";withdrawals:" << BLUE << _nbWithdrawals << WHITE
			  << std::endl;
}
