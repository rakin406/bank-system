#ifndef BANK_H
#define BANK_H

#include "utils.h"

#include <string_view>

// TODO: Implement SQL for account saving

struct Account
{
    std::string_view name{};        // Client name
    unsigned int age{};             // Client age
    std::string_view phoneNumber{}; // Phone number of client

    bool operator==(const Account& acc) const
    {
        return (name == acc.name) && (age == acc.age) &&
               (phoneNumber == acc.phoneNumber);
    }
};

namespace utils::account
{
    /**
     * @brief Return true if client age is valid.
     *
     * @param age Client age.
     *
     * @return boolean.
     */
    bool isAgeValid(unsigned int age);

    /**
     * @brief Return true if phone number is valid.
     *
     * @param phoneNumber Phone number of client.
     *
     * @return boolean.
     */
    bool isPhoneNumberValid(std::string_view phoneNumber);

    /**
     * @brief Return true if all account informations are valid.
     *
     * @param account Client account.
     *
     * @return boolean.
     */
    bool isAccountValid(const Account& account);

    /**
     * @brief Format and clean the account informations.
     *
     * @param Client account.
     *
     * @return account Account struct.
     */
    Account getFormattedInfo(Account account);

} // namespace utils::account

/**
 * @brief This class is for account management and money transactions.
 */
class Bank
{
public:
    /**
     * @brief Default constructor for Bank initialization.
     */
    Bank();

    /**
     * @brief Create bank account with necessary information.
     *
     * @param account Account structure containing information about the client.
     *
     * @return true if account is created.
     */
    bool createAccount(const Account& account);

    /**
     * @brief Return true if account is eligible for bank.
     *
     * @return boolean.
     */
    [[nodiscard]] bool isEligible() const;

private:
    // std::string_view password;  // TODO: Future idea
    Account m_account; // Client account
    bool m_eligible{}; // Boolean for bank allowance
    // int m_deposit;
    // int m_withdrawal;
    // int m_savings;
    std::string_view m_country{}; // Local country
};

#endif