#include "../include/account.h"
#include "../include/utils.h"

#include <string_view>

namespace
{
    constexpr unsigned int MINIMUM_AGE = 18;
}

// TODO: Test this
bool Account::isNameValid() const { return !name.empty(); }

bool Account::isAgeValid() const { return age >= MINIMUM_AGE; }

// TODO: Test this
bool Account::isValid() { return isNameValid() && isAgeValid(); }

// TODO: Test this
void Account::format() { name = utils::trim(name); }
