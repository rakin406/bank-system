#include "../include/account.h"

#include <catch2/catch_test_macros.hpp>

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
