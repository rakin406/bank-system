#include "../include/accountManager.h"
#include "../include/utils.h"

#include <string>
#include <algorithm>

namespace
{
    // unsigned int getAgeFromBirthDate();

    /**
     * @brief Format and clean the account informations.
     *
     * @param account.
     */
    void formatAccountInfo(Account& account)
    {
        using utils::trim;

        // Clean up leading and trailing white spaces
        account.name = trim(static_cast<std::string>(account.name));
        account.birthDate = trim(static_cast<std::string>(account.birthDate));
        account.phoneNumber =
            trim(static_cast<std::string>(account.phoneNumber));
    }

} // namespace

// TODO: Test this function
void AccountManager::createAccount(const Account& account)
{
    m_account = account;
    formatAccountInfo(m_account);
}

bool AccountManager::isEligible() const { return m_eligible; }

// bool AccountManager::isBirthDateValid() {}

// bool AccountManager::isPhoneNumberValid() {}
