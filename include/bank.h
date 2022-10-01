#ifndef BANK_H
#define BANK_H

#include "client.h"

#include <string_view>

// TODO: Implement JSON for loading bank information

/**
 * @brief This class is for client management and money transactions.
 */
class Bank
{
public:
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
     * @brief Get the amount of savings for client.
     *
     * @return integer of savings.
     */
    [[nodiscard]] int getSavings() const;

private:
    Client* m_client{ nullptr }; // Client structure
    int m_savings{ 0 };          // Money savings in bank
};

#endif
