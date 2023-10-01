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
#include "../inc/colors.h"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalNbDeposits = 0;
	_nbDeposits = 0;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << " index:"<< BLUE << _accountIndex << RESET;
	std::cout << ";amount:" << BLUE << _amount << RESET;
	std::cout << ";created" << std::endl;
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
	std::cout << " accounts:" << BLUE << _nbAccounts << RESET;
	std::cout << ";total:" << BLUE << _totalAmount << RESET;
	std::cout << ";deposits:" << BLUE << _totalNbDeposits << RESET;
	std::cout << ";withdrawals:" << BLUE << _totalNbWithdrawals << RESET << std::endl;
}
void Account::makeDeposit(int deposit) 
{
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET;
	std::cout << ";p_amount:" << BLUE << _amount << RESET;
	std::cout << ";deposit:" << BLUE << deposit << RESET;
	_amount += deposit;
	std::cout << ";amount:" << BLUE << _amount << RESET;
	std::cout << ";nb_deposits:" << BLUE << _nbDeposits << RESET << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) 
{
	_displayTimestamp();
	if (withdrawal <= _amount)
	{
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << " index:" << BLUE << _accountIndex << RESET;
		std::cout << ";p_amount:" << BLUE << _amount << RESET;
		std::cout << ";withdrawal:" << BLUE << withdrawal << RESET;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << ";amount:" << BLUE << _amount << RESET;
		std::cout << ";nb_withdrawals:" << BLUE << _nbWithdrawals << RESET << std::endl;
		return (true);
	}
	std::cout << " index:" << BLUE << _accountIndex << RESET;
	std::cout << ";p_amount:" << BLUE << _amount << RESET;
	std::cout << ";withdrawal:refused" << std::endl;

	return (false);
}
int Account::checkAmount() const 
{
	return (_totalAmount);
}
void Account::displayStatus() const 
{
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET;
	std::cout << ";amount:" << BLUE << _amount << RESET;
	std::cout << ";deposits:" << BLUE << _nbDeposits << RESET;
	std::cout << ";withdrawals:" << BLUE << _nbWithdrawals << RESET;
	std::cout << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET;
	std::cout << ";amount:" << BLUE << _amount << RESET;
	std::cout << ";closed" << std::endl;
	_amount = 0;
	_accountIndex = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
