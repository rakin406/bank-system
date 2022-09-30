#include "../include/bank.h"
#include "../include/account.h"
#include "../include/utils.h"

bool Bank::createAccount(Account* account, int initialDeposit)
{
    if (account->isWalletValid() && initialDeposit > 0)
    {
        m_account = account;
        deposit(initialDeposit);
        return true; // Account is successfuly registered
    }
    return false;
}

bool Bank::accountExists() { return m_account != nullptr; }

bool Bank::deposit(int amount)
{
    if ((amount > 0) && (accountExists()) && (m_account->wallet - amount > 0))
    {
        // Transfer cash from wallet to savings
        m_account->wallet -= amount;
        m_savings += amount;
        return true; // Successful deposit
    }
    return false;
}

// TODO: Test this
bool Bank::withdraw(int amount)
{
    if ((amount > 0) && (accountExists()) && (m_savings - amount > 0))
    {
        // Transfer cash from savings to wallet
        m_savings -= amount;
        m_account->wallet += amount;
        return true; // Successful withdraw
    }
    return false;
}

bool Bank::depositAll()
{
    if (accountExists())
    {
        // Transfer all cash from wallet to savings
        m_savings += m_account->wallet;
        m_account->wallet = 0;
        return true; // Successful deposit
    }
    return false;
}

// TODO: Test this
bool Bank::withdrawAll()
{
    if (accountExists())
    {
        // Transfer all cash from savings to wallet
        m_account->wallet += m_savings;
        m_savings = 0;
        return true; // Successful withdraw
    }
    return false;
}

int Bank::getSavings() const { return m_savings; }
