#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts( void )
{
    return 1;
}
int	Account::getTotalAmount( void )
{
    return 1;
}
int	Account::getNbDeposits( void )
{
    return 1;
}
int	Account::getNbWithdrawals( void )
{
    return 1;
}
void	Account::displayAccountsInfos( void )
{

}

void	Account::makeDeposit( int deposit )
{
    (void)deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    (void) withdrawal;
    return true;
}
int		Account::checkAmount( void ) const
{
    return 1;
}
void	Account::displayStatus( void ) const
{

}
void	Account::_displayTimestamp( void )
{

}

Account::Account(int initialBalance)
{
    initialBalance = 0;
    std::cout << initialBalance << std::endl;
}

Account::~Account()
{
}