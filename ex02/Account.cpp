// ************************************************************************************************ //
//                                                                                                  //
//                Account.hpp for GlobalBanksters United                                            //
//                Created on  : Fri Aug 19 10:01:15 2022                                            //
//                Last update : Fri Aug 19 10:01:06 2022                                            //
//                Made by : Matteo "Erumar" Marinelli <mmarinel@student.42roma.it>                  //
//                                                                                                  //
// ************************************************************************************************ //

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

static int	range_spill(int value, int left, int right);
//* end of static declarations


//* assigning static storage

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//* methods implementation

void	Account::makeDeposit( int deposit )
{
	if (deposit <= 0)
		return ;
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount + deposit
		<< ";nb_deposits:" << this->_nbDeposits + 1
		<< std:: endl;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	//* I would have liked to add a custom Exception in the .hpp file!
	_displayTimestamp();
	if (withdrawal <= this->_amount)
	{
		std::cout
			<< " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount - withdrawal
			<< ";nb_withdrawals:" << this->_nbWithdrawals + 1
			<< std:: endl;
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		return (true);
	}
	else
	{
		std::cout
			<< " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:" << "refused"
			<< std::endl;
		return (false);
	}
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std:: endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;
	_nbAccounts -= 1;
	_totalAmount -= this->_amount;
	//* Don't know if I should subtract withdrawals and deposits too.
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp( void )
{
	struct tm	*timestamp;
	time_t		elapsed_scs;

	elapsed_scs = time(NULL);
	timestamp = localtime(&elapsed_scs);
	std::cout
		<< "["
		<< std::setw(2) << std::setfill('0') << timestamp->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << timestamp->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << timestamp->tm_mday
		<< std::setw(2) << std::setfill('0') << "_"
		<< std::setw(2) << std::setfill('0') << timestamp->tm_hour
		<< std::setw(2) << std::setfill('0') << timestamp->tm_min
		<< std::setw(2) << std::setfill('0') << range_spill(timestamp->tm_sec, 0, 60)
		<< "]";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

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

/**
 * @brief this function maps numbers >= [right] to [left]
 * and numbers <= [left] to [left].
 * 
 * @param value 
 * @param left 
 * @param right 
 * @return int 
 */
static int	range_spill(int value, int left, int right)
{
	if (value >= right)
		return (left);
	else if (value < left)
		return (left);
	else
		return (value);
}
