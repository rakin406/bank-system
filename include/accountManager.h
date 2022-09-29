#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string_view>

// TODO: Implement SQL for account saving

struct Account
{
    std::string_view name{};        // Name of client
    std::string_view birthDate{};   // Birth date of client
    std::string_view phoneNumber{}; // Phone number of client

    /**
     * @brief Check for struct equality.
     *
     * @param acc Account struct.
     *
     * @return boolean.
     */
    bool operator==(const Account& acc) const
    {
        return (name == acc.name) && (birthDate == acc.birthDate) &&
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
    void createAccount(const Account& account);

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

    /**
     * @brief Format and clean the account informations.
     *
     * @param account.
     */
    void formatAccountInfo(const Account& account);

    // unsigned int getAgeFromBirthDate();

    /**
     * @brief Return true if birth date is valid.
     *
     * @return boolean.
     */
    bool isBirthDateValid();

    /**
     * @brief Return true if phone number is valid.
     *
     * @return boolean.
     */
    bool isPhoneNumberValid();

    // void makeEligible();
};

#endif
