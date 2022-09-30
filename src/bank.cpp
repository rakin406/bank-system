#include "../include/bank.h"
#include "../include/client.h"
#include "../include/utils.h"

bool Bank::registerClient(Client* client, int initialDeposit)
{
    if (client->isWalletValid() && initialDeposit > 0)
    {
        m_client = client;
        deposit(initialDeposit);
        return true; // Client is successfuly registered
    }
    return false;
}

bool Bank::clientExists() { return m_client != nullptr; }

bool Bank::deposit(int amount)
{
    if ((amount > 0) && (clientExists()) && (m_client->wallet - amount > 0))
    {
        // Transfer cash from wallet to savings
        m_client->wallet -= amount;
        m_savings += amount;
        return true; // Successful deposit
    }
    return false;
}

// TODO: Test this
bool Bank::withdraw(int amount)
{
    if ((amount > 0) && (clientExists()) && (m_savings - amount > 0))
    {
        // Transfer cash from savings to wallet
        m_savings -= amount;
        m_client->wallet += amount;
        return true; // Successful withdraw
    }
    return false;
}

bool Bank::depositAll()
{
    if (clientExists())
    {
        // Transfer all cash from wallet to savings
        m_savings += m_client->wallet;
        m_client->wallet = 0;
        return true; // Successful deposit
    }
    return false;
}

// TODO: Test this
bool Bank::withdrawAll()
{
    if (clientExists())
    {
        // Transfer all cash from savings to wallet
        m_client->wallet += m_savings;
        m_savings = 0;
        return true; // Successful withdraw
    }
    return false;
}

int Bank::getSavings() const { return m_savings; }
