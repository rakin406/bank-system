#include "../include/bank.h"
#include "../include/account.h"
#include "../include/utils.h"

bool Bank::createAccount(Account& account)
{
    // Remove leading and trailing white spaces in account information
    account.format();

    if (account.isValid())
    {
        m_eligible = true;
        m_account = account;
        return true; // Account is successfuly registered
    }
    return false;
}

bool Bank::isEligible() const { return m_eligible; }
