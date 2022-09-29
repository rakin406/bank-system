#include "../include/accountManager.h"

#include <catch2/catch_test_macros.hpp>

// ------- namespace utils::account functions ---------- //

TEST_CASE("utils::account::isAgeValid() returns correct boolean"
          "(pass)",
          "[multi-file:3]")
{
    REQUIRE(utils::account::isAgeValid(15) == false);
    REQUIRE(utils::account::isAgeValid(18) == true);
    REQUIRE(utils::account::isAgeValid(30) == true);
}

// TODO: Test isPhoneNumberValid()
// TEST_CASE("utils::account::isPhoneNumberValid() returns correct boolean"
//           "(pass)",
//           "[multi-file:3]")
// {
//     REQUIRE(utils::account::isAgeValid(15) == false);
//     REQUIRE(utils::account::isAgeValid(18) == true);
//     REQUIRE(utils::account::isAgeValid(30) == true);
// }

// ------------- AccountManager Methods ---------------- //

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
