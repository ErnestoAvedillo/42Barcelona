/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:05:04 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/17 15:05:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_totalNbDeposits = 0;
	_nbDeposits = 0;
	_totalAmount = initial_deposit;
	_displayTimestamp();
	std::cout << "index : " << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	struct tm *tstruct = localtime(&now);
	char buff[20];
	strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S]", tstruct);
	std::cout << buff;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void) 
{
	return _totalAmount;
}

int Account::getNbDeposits(void)  
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) 
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << "total:" << _totalAmount;
	std::cout << "deposits:" << _totalNbDeposits;
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit) 
{
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index : " << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;

//	"[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1"
}

bool Account::makeWithdrawal(int withdrawal) 
{
	if (withdrawal <= _totalAmount)
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index : " << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
		return (true);
//		"[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1"
	}
	std::cout << "index : " << _accountIndex << ";amount:" << _amount << ";refused" << std::endl;
//	"[19920104_091532] index:0;p_amount:47;withdrawal:refused"

		return (false);
}
int Account::checkAmount() const 
{
	return (_totalAmount);
}
void Account::displayStatus() const {}

Account::~Account()
{
	_amount = 0;
	_accountIndex = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
