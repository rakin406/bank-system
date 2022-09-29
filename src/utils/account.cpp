#include "../../include/utils/account.h"
#include "../../include/accountManager.h"

namespace utils::account
{
    // unsigned int getAgeFromBirthDate();

    Account formatAccountInfo(const Account& account)
    {
        using utils::trim;

        Account newAccount{};

        // Clean up leading and trailing white spaces
        newAccount.name = trim(account.name);
        newAccount.birthDate = trim(account.birthDate);
        newAccount.phoneNumber = trim(account.phoneNumber);

        return newAccount;
    }

} // namespace utils::account
