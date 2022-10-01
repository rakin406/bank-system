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

Bank::~Bank() { saveToFile(); }

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

// TODO: Test this
const Client& Bank::getClient() const { return *m_client; }

int Bank::getSavings() const { return m_savings; }

void Bank::saveToFile()
{
    using nlohmann::json;

    // Store member variable values in JSON format
    json obj;
    json client;
    client["wallet"] = m_client->wallet;
    client["savings"] = m_savings;
    obj["client"] = client;

    // Write prettified JSON to file
    std::ofstream file{ static_cast<std::string>(JSON_FILE) };
    file << std::setw(4) << obj << std::endl;
}

void Bank::loadFromFile()
{
    using nlohmann::json;

    std::ifstream file{ static_cast<std::string>(JSON_FILE) };

    if (!file)
    {
        return;
    }

    json data{ json::parse(file) };

    // Client pointer needs to point to something otherwise segfault will occur
    Client dummy{};
    m_client = &dummy;

    m_client->wallet = data["client"]["wallet"];
    m_savings = data["client"]["savings"];
}
