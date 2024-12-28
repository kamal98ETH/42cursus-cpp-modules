/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:52:12 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/28 13:39:31 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}


Account::Account(int initial_deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_accountIndex = getNbAccounts() -1;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex
				<< ";amount:" << checkAmount()
				<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_amount += deposit;
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex
				<< ";p_amount:" << Account::_amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << Account::_amount
				<< ";nb_deposits:" << Account::_nbDeposits
				<< std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex
				<< ";p_amount:" << checkAmount()
				<< ";withdrawal:";
	
	if (withdrawal <= checkAmount())
	{
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		std::cout	<< withdrawal
				<< ";amount:" << checkAmount()
				<< ";nb_withdrawals:" << Account::_nbWithdrawals
				<< std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex
				<< ";amount:" << checkAmount()
				<< ";deposits:" << Account::_nbDeposits
				<< ";withdrawals:" << Account::_nbWithdrawals
				<< std::endl;

}

void	Account::_displayTimestamp( void )
{
	time_t	now = time(0);
	tm*	localTime = localtime(&now);
	std::cout	<< std::setfill('0')
				<< "["
				<< localTime->tm_year +1900 
				<< std::setw(2) << localTime->tm_mon +1
				<< std::setw(2) << localTime->tm_mday
				<< "_"
				<< std::setw(2) << localTime->tm_hour
				<< std::setw(2) << localTime->tm_min
				<< std::setw(2) << localTime->tm_sec
				<< "] ";
}
