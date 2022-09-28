#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string_view>

// TODO: Implement SQL for account saving

/**
 * @brief This class contains methods for managing and creating accounts.
 */
class AccountManager
{
public:
    struct Account
    {
        std::string_view name{};        // Name of client
        std::string_view birthDate{};   // Birth date of client
        std::string_view phoneNumber{}; // Phone number of client
    };

    /**
     * @brief Default constructor for Account Manager initialization.
     */
    // AccountManager();

    /**
     * @brief Get birth date.
     *
     * @return birth date.
     */
    // [[nodiscard]] std::string_view getBirthDate() const;

    /**
     * @brief Set birth date.
     */
    // void setBirthDate();

    /**
     * @brief Get phone number.
     *
     * @return phone number.
     */
    // [[nodiscard]] int getPhoneNumber() const;

    /**
     * @brief Set phone number.
     */
    // void setPhoneNumber();

    /**
     * @brief Create bank account with necessary information.
     *
     * @param account Account structure containing information about the client.
     */
    void createAccount(Account account);

    [[nodiscard]] bool isEligible() const;

private:
    // std::string_view password;  // TODO: Future idea
    Account account;   // Client account
    bool m_eligible{}; // Boolean for bank allowance

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
