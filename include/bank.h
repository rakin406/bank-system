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
     *
     * @return true if account is created.
     */
    bool createAccount(Account& account);

    /**
     * @brief Return true if account is eligible for bank.
     *
     * @return boolean.
     */
    [[nodiscard]] bool isEligible() const;

private:
    // std::string_view password;
    Account m_account; // Client account
    bool m_eligible{}; // Boolean for bank allowance
    // int m_deposit;
    // int m_withdrawal;
    // int m_savings;
};

#endif
