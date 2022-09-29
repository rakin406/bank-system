#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <string_view>

/**
 * @brief This class contains the functionalities of the bank.
 */
class BankSystem
{
public:
    /**
     * @brief Default constructor for Bank System initialization.
     */
    BankSystem();

    /**
     * @brief Get country member variable.
     *
     * @return country as string.
     */
    [[nodiscard]] std::string_view getCountry() const;

private:
    // int m_deposit;
    // int m_withdrawal;
    // int m_savings;
    std::string_view m_country{}; // Local country

    // TODO: Implement this
    /**
     * @brief Get local country using HTTP request.
     *
     * @return country as string.
     */
    std::string_view getLocalCountry();
};

#endif
