#include "../include/account.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Account struct \"==\" comparison returns true"
          "(pass)",
          "[multi-file:2]")
{
    Account account{ "Darth Vader", 18 };
    Account duplicate{ account };
    REQUIRE(duplicate == account);
}

TEST_CASE("Account::isNameValid() returns correct boolean"
          "(pass)",
          "[multi-file:2]")
{
    Account account{};

    account.name = "batman";
    REQUIRE(account.isNameValid() == true);

    account.name = "";
    REQUIRE(account.isNameValid() == false);
}

TEST_CASE("Account::isAgeValid() returns correct boolean"
          "(pass)",
          "[multi-file:2]")
{
    Account account{};

    // Negative age check
    account.age = -20;
    REQUIRE(account.isAgeValid() == false);

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

TEST_CASE("Account::isWalletValid() returns correct boolean"
          "(pass)",
          "[multi-file:2]")
{
    Account account{};

    account.wallet = 0;
    REQUIRE(account.isWalletValid() == false);

    account.wallet = -1500;
    REQUIRE(account.isWalletValid() == false);

    account.wallet = 3000;
    REQUIRE(account.isWalletValid() == true);
}

TEST_CASE("Account::isValid() returns correct boolean"
          "(pass)",
          "[multi-file:2]")
{
    Account account{ "batman", 30 };
    REQUIRE(account.isValid() == true);

    account = { "", 0 };
    REQUIRE(account.isValid() == false);

    account = { "batman", 0 };
    REQUIRE(account.isValid() == false);

    account = { "", 30 };
    REQUIRE(account.isValid() == false);
}
