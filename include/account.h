#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string_view>

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

    /**
     * @brief Return true if client age is valid.
     *
     * @return boolean.
     */
    [[nodiscard]] bool isAgeValid() const;

    /**
     * @brief Return true if phone number is valid.
     *
     * @return boolean.
     */
    bool isPhoneNumberValid();

    /**
     * @brief Return true if all account informations are valid.
     *
     * @return boolean.
     */
    bool isValid();

    /**
     * @brief Format and clean the account informations.
     */
    void format();
};

#endif
