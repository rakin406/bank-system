#include "../include/accountManager.h"
#include "../include/utils/utils.h"

void AccountManager::createAccount(const Account& account)
{
    formatAccountInfo(account);
}

void AccountManager::formatAccountInfo(const Account& account)
{
    using utils::trim;

    // Clean up leading and trailing white spaces
    m_account.name = trim(account.name);
    m_account.birthDate = trim(account.birthDate);
    m_account.phoneNumber = trim(account.phoneNumber);
}

bool AccountManager::isEligible() const { return m_eligible; }

Account AccountManager::getAccount() const { return m_account; }

// bool AccountManager::isBirthDateValid() {}

// bool AccountManager::isPhoneNumberValid() {}
