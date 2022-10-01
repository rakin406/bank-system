#include "../include/bank.h"

#include "../include/client.h"
#include "../include/utils.h"

#include <nlohmann/json.hpp>

#include <fstream>
#include <string>
#include <string_view>

namespace
{
    constexpr std::string_view JSON_FILE{ "client.json" };
}

Bank::Bank() { loadFromFile(); }

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

bool Bank::saveToFile()
{
    using nlohmann::json;

    // Store member variable values in JSON format
    json data{ { "client",
                 { { "wallet", m_client->wallet },
                   { "savings", m_savings } } } };

    // Write prettified JSON to file
    std::ofstream file{ static_cast<std::string>(JSON_FILE) };
    return static_cast<bool>(file << std::setw(4) << data << std::endl);
}

bool Bank::loadFromFile()
{
    using nlohmann::json;

    std::ifstream file{ static_cast<std::string>(JSON_FILE) };
    json data{ json::parse(file) };

    if (file && data)
    {
        m_client->wallet = data["client"]["wallet"];
        m_savings = data["client"]["savings"];
        return true;
    }

    return false;
}
