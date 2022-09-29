#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "utils.h"
#include "../accountManager.h"

namespace utils::account
{
    // unsigned int getAgeFromBirthDate();

    /**
     * @brief Format and clean the account informations.
     *
     * @param account.
     */
    void formatAccountInfo(Account& account);

} // namespace utils::account

#endif
