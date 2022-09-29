#include "../include/account.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Account struct \"==\" comparison returns true"
          "(pass)",
          "[multi-file:2]")
{
    Account account{ "Darth Vader", 18, "" };
    Account duplicate{ account };
    REQUIRE(duplicate == account);
}

TEST_CASE("Account::isAgeValid() returns correct boolean"
          "(pass)",
          "[multi-file:2]")
{
    Account account;

    // Underage check
    account.age = 15;
    REQUIRE(account.isAgeValid() == false);

    // Exact 18YO check
    account.age = 18;
    REQUIRE(account.isAgeValid() == true);

    // >18YO check
    account.age = 30;
    REQUIRE(account.isAgeValid() == true);
}

// TODO: Test isPhoneNumberValid()
// TEST_CASE("utils::account::isPhoneNumberValid() returns correct boolean"
//           "(pass)",
//           "[multi-file:2]")
// {
//     REQUIRE(utils::account::isAgeValid(15) == false);
//     REQUIRE(utils::account::isAgeValid(18) == true);
//     REQUIRE(utils::account::isAgeValid(30) == true);
// }
