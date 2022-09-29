#include "../include/accountManager.h"
#include "../include/utils.h"

#include <string_view>

namespace
{
    constexpr unsigned int MINIMUM_AGE = 18;

    /**
     * @brief Return true if client age is valid.
     *
     * @param age Client age.
     *
     * @return boolean.
     */
    bool isAgeValid(unsigned int age) { return age >= MINIMUM_AGE; }

    // TODO: Implement this
    /**
     * @brief Return true if phone number is valid.
     *
     * @param phoneNumber Phone number of client.
     *
     * @return boolean.
     */
    bool isPhoneNumberValid(std::string_view phoneNumber) { return true; }

    /**
     * @brief Return true if all account informations are valid.
     *
     * @param account Client account.
     *
     * @return boolean.
     */
    bool isAccountValid(const Account& account)
    {
        return isAgeValid(account.age) &&
               isPhoneNumberValid(account.phoneNumber);
    }

    /**
     * @brief Format and clean the account informations.
     *
     * @param Client account.
     *
     * @return account Account struct.
     */
    Account getFormattedInfo(Account account)
    {
        using utils::trim;

        // Clean up leading and trailing white spaces
        account.name = trim(account.name);
        account.phoneNumber = trim(account.phoneNumber);

        return account;
    }

} // namespace

bool AccountManager::create(const Account& account)
{
    Account formattedAccount = getFormattedInfo(account);
    if (isAccountValid(formattedAccount))
    {
        m_eligible = true;
        m_account = formattedAccount;
        return true; // Account is successfuly registered
    }
    return false;
}

bool AccountManager::isEligible() const { return m_eligible; }
