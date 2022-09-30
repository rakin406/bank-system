#include "../include/bank.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Bank::clientExists() returns false on initialization"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    REQUIRE(bank.clientExists() == false);
}

TEST_CASE("Bank::getSavings() returns 0 on initialization"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    REQUIRE(bank.getSavings() == 0);
}
