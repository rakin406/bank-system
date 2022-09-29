#include "../include/accountManager.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Account struct \"==\" comparison returns true"
          "(pass)",
          "[multi-file:3]")
{
    Account account{ "Darth Vader", "", "" };
    Account duplicate{ account };
    REQUIRE(duplicate == account);
}

TEST_CASE("utils::account::formatAccountInfo() passes test"
          "(pass)",
          "[multi-file:2]")
{
    Account account{ "   Darth Vader   ", "   1/01/2022   ", "   911   " };
    account = utils::account::formatAccountInfo(account);

    // Must not have any leading or trailing white spaces
    REQUIRE(account.name == "Darth Vader");
    REQUIRE(account.birthDate == "1/01/2022");
    REQUIRE(account.phoneNumber == "911");
}

TEST_CASE("AccountManager::isEligible() method returns false on initialization "
          "(pass)",
          "[multi-file:3]")
{
    AccountManager manager;
    REQUIRE(manager.isEligible() == false);
}

TEST_CASE("AccountManager::getAccount() method returns account"
          "(pass)",
          "[multi-file:3]")
{
    AccountManager manager;
    Account account{ "Darth Vader", "", "" };
    manager.createAccount(account);
    REQUIRE(manager.getAccount() == account);
}
