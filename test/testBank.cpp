#include "../include/bank.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Bank::create() creates account successfully"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    Account account{ "Darth Vader", 18, "" };
    REQUIRE(bank.createAccount(account) == true);
}

TEST_CASE("Bank::isEligible() returns false on initialization"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    REQUIRE(bank.isEligible() == false);
}
