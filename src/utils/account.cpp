#include "../../include/utils/account.h"
#include "../../include/accountManager.h"

namespace utils::account
{
    // unsigned int getAgeFromBirthDate();

    // TODO: Test this function
    void formatAccountInfo(Account& account)
    {
        using utils::trim;

        // Clean up leading and trailing white spaces
        account.name = trim(account.name);
        account.birthDate = trim(account.birthDate);
        account.phoneNumber = trim(account.phoneNumber);
    }

} // namespace utils::account
