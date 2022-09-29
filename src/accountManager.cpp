#include "../include/accountManager.h"
#include "../include/utils.h"

#include <string_view>

static constexpr unsigned int MINIMUM_AGE = 18;

namespace utils::account
{
    bool isAgeValid(unsigned int age) { return age >= MINIMUM_AGE; }

    // TODO: Implement this
    bool isPhoneNumberValid(std::string_view phoneNumber) { return true; }

    // TODO: Test this
    bool isAccountValid(const Account& account)
    {
        return isAgeValid(account.age) &&
               isPhoneNumberValid(account.phoneNumber);
    }

    // TODO: Test this
    Account getFormattedInfo(Account account)
    {
        using utils::trim;

        // Clean up leading and trailing white spaces
        account.name = trim(account.name);
        account.phoneNumber = trim(account.phoneNumber);

        return account;
    }
} // namespace utils::account

AccountManager::AccountManager() { m_country = utils::net::getLocalCountry(); }

bool AccountManager::create(const Account& account)
{
    using namespace utils::account;
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
