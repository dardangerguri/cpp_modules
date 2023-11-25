/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:35:55 by dardangergu       #+#    #+#             */
/*   Updated: 2023/11/25 18:59:12 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << checkAmount() << ";closed" << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::_displayTimestamp(void) {
	std::time_t	Time = std::time(NULL);
	std::tm		*LocalTime = std::localtime(&Time);
	std::cout	<< std::put_time(LocalTime, "[%Y%m%d_%OH%OM%OS]");
}

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
		_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << checkAmount() - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << checkAmount()
				<< ";withdrawal:";
	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout	<< withdrawal
					<< ";amount:" << checkAmount()
					<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:"	<< _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout 	<< " accounts:" << getNbAccounts()
					<< ";total:" << getTotalAmount()
					<< ";deposits:" << getNbDeposits()
					<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}
