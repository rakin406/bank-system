#include "../include/accountManager.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Account struct \"==\" comparison returns true"
          "(pass)",
          "[multi-file:3]")
{
    Account account{ "Darth Vader", 18, "" };
    Account duplicate{ account };
    REQUIRE(duplicate == account);
}

TEST_CASE("AccountManager::create() creates account successfully"
          "(pass)",
          "[multi-file:3]")
{
    AccountManager manager;
    Account account{ "Darth Vader", 18, "" };
    REQUIRE(manager.create(account) == true);
}

TEST_CASE("AccountManager::isEligible() returns false on initialization"
          "(pass)",
          "[multi-file:3]")
{
    AccountManager manager;
    REQUIRE(manager.isEligible() == false);
}
