#include "../include/accountManager.h"
#include "../include/utils/account.h"

void AccountManager::createAccount(const Account& account)
{
    m_account = utils::account::formatAccountInfo(account);
}

bool AccountManager::isEligible() const { return m_eligible; }

Account AccountManager::getAccount() const { return m_account; }

// bool AccountManager::isBirthDateValid() {}

// bool AccountManager::isPhoneNumberValid() {}
