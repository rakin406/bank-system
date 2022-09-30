#ifndef BANK_H
#define BANK_H

#include "account.h"

#include <string_view>

// TODO: Implement SQL for account saving

/**
 * @brief This class is for account management and money transactions.
 */
class Bank
{
public:
    /**
     * @brief Create bank account with necessary information.
     *
     * @param account Account structure containing information about the client.
     * @param initialDeposit Necessary initial deposit from client.
     *
     * @return true if account is created.
     */
    bool createAccount(Account* account, int initialDeposit);

    /**
     * @brief Ensure account is not null and does exist.
     *
     * @return boolean.
     */
    bool accountExists();

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
    // std::string_view password;
    Account* m_account{ nullptr }; // Client account
    int m_savings{ 0 };            // Money savings in bank
};

#endif
