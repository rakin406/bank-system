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
    void setBirthDate();

    /**
     * @brief Get phone number.
     *
     * @return phone number.
     */
    // [[nodiscard]] int getPhoneNumber() const;

    /**
     * @brief Set phone number.
     */
    void setPhoneNumber();

    [[nodiscard]] bool isEligible() const;

private:
    // std::string_view password;  // TODO: Future idea
    std::string_view m_birthDate{}; // Birth date of the user
    int m_phoneNumber{};            // Phone number of the user
    bool m_eligible{};              // Boolean for bank allowance
};

#endif
