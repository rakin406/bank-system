#include "../include/account.h"
#include "../include/utils.h"

#include <string_view>

namespace
{
    constexpr unsigned int MINIMUM_AGE = 18;
}

bool Account::isAgeValid() const { return age >= MINIMUM_AGE; }

// TODO: Implement this
bool Account::isPhoneNumberValid() { return true; }

// TODO: Test this
bool Account::isValid() { return isAgeValid() && isPhoneNumberValid(); }

// TODO: Test this
void Account::format()
{
    using utils::trim;

    // Clean up leading and trailing white spaces
    name = trim(name);
    phoneNumber = trim(phoneNumber);
}
