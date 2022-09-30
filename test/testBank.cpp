#include "../include/bank.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Bank::createAccount() creates account successfully"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    Account account{ 3000 };
    REQUIRE(bank.createAccount(&account, 2000) == true);
}

TEST_CASE("Bank::accountExists() returns false on initialization"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    REQUIRE(bank.accountExists() == false);
}

TEST_CASE("Bank::deposit() returns true on successful deposit"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    Account account{ 3000 };
    bank.createAccount(&account, 100);
    REQUIRE(bank.deposit(2000) == true);
}

TEST_CASE("Bank::depositAll() returns true on successful deposit"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    Account account{ 3000 };
    bank.createAccount(&account, 100);
    REQUIRE(bank.depositAll() == true);
}

TEST_CASE("Bank::getSavings() returns 0 on initialization"
          "(pass)",
          "[multi-file:2]")
{
    Bank bank;
    REQUIRE(bank.getSavings() == 0);
}
