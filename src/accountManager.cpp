#include "../include/accountManager.h"
#include "../include/utils.h"

namespace
{
    constexpr unsigned int MINIMUM_AGE = 18;

    // TODO: Implement this
    unsigned int getAgeFromBirthDate(const Account& account) {}

    // TODO: Implement this
    /**
     * @brief Return true if birth date is valid.
     *
     * @param account Client account.
     *
     * @return boolean.
     */
    bool isBirthDateValid(const Account& account) {}

    // TODO: Implement this
    /**
     * @brief Return true if phone number is valid.
     *
     * @param account Client account.
     *
     * @return boolean.
     */
    bool isPhoneNumberValid(const Account& account) {}

    /**
     * @brief Return true if all account informations are valid.
     *
     * @param account Client account.
     *
     * @return boolean.
     */
    bool isAccountValid(const Account& account)
    {
        return isBirthDateValid(account) && isPhoneNumberValid(account);
    }

    /**
     * @brief Format and clean the account informations.
     *
     * @param Client account.
     */
    Account getFormattedInfo(Account account)
    {
        using utils::trim;

        // Clean up leading and trailing white spaces
        account.name = trim(account.name);
        account.birthDate = trim(account.birthDate);
        account.phoneNumber = trim(account.phoneNumber);

        return account;
    }

} // namespace

void AccountManager::create(const Account& account)
{
    if (isAccountValid(account))
    {
        m_eligible = true;
        m_account = getFormattedInfo(account);
    }
}

bool AccountManager::isEligible() const { return m_eligible; }
