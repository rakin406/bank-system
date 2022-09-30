#include "../include/account.h"
#include "../include/utils.h"

#include <string_view>

namespace
{
    constexpr int MINIMUM_AGE = 18;
}

bool Account::isNameValid() const { return !name.empty(); }

bool Account::isAgeValid() const { return age >= MINIMUM_AGE; }

bool Account::isValid() { return isNameValid() && isAgeValid(); }

void Account::format() { name = utils::trim(name); }
