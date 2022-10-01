#ifndef BANK_H
#define BANK_H

#include "client.h"

#include <string_view>

/**
 * @brief This class is for client management and money transactions.
 */
class Bank
{
public:
    /**
     * @brief Bank constructor.
     */
    Bank();

    /**
     * @brief Bank destructor.
     */
    ~Bank();

    /**
     * @brief Register bank client with necessary information.
     *
     * @param client Structure containing information about the client.
     * @param initialDeposit Necessary initial deposit from client.
     *
     * @return true if client is registered.
     */
    bool registerClient(Client* client, int initialDeposit);

    /**
     * @brief Ensure client is not null and does exist.
     *
     * @return boolean.
     */
    bool clientExists();

    /**
     * @brief Deposit cash to bank.
     *
     * @param amount Amount of cash.
     *
     * @return true if deposit is successful.
     */
    bool deposit(int amount);

    /**
     * @brief Withdraw cash from bank.
     *
     * @param amount Amount of cash.
     *
     * @return true if withdrawal is successful.
     */
    bool withdraw(int amount);

    /**
     * @brief Deposit all wallet cash to bank.
     *
     * @return true if deposit is successful.
     */
    bool depositAll();

    /**
     * @brief Withdraw all cash from bank.
     *
     * @return true if withdrawal is successful.
     */
    bool withdrawAll();

    /**
     * @brief Get registered client.
     *
     * @return client.
     */
    [[nodiscard]] const Client& getClient() const;

    /**
     * @brief Get the amount of savings for client.
     *
     * @return integer of savings.
     */
    [[nodiscard]] int getSavings() const;

private:
    Client* m_client{}; // Client structure
    int m_savings{};    // Money savings in bank

    /**
     * @brief Save bank and client information to JSON file
     */
    void saveToFile();

    /**
     * @brief Load bank and client information from JSON file
     */
    void loadFromFile();
};

#endif
