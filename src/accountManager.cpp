#include "../include/accountManager.h"
#include "../include/utils/account.h"

#include <string>
#include <algorithm>

// TODO: Test this function
void AccountManager::createAccount(const Account& account)
{
    m_account = utils::account::formatAccountInfo(account);
}

bool AccountManager::isEligible() const { return m_eligible; }

// bool AccountManager::isBirthDateValid() {}

// bool AccountManager::isPhoneNumberValid() {}
