#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

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

/**
 * @brief This class contains methods for managing and creating accounts.
 */
class AccountManager
{
public:
    /**
     * @brief Create bank account with necessary information.
     *
     * @param account Account structure containing information about the client.
     */
    void create(const Account& account);

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
};

#endif
