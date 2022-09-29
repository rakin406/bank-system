#include "../include/accountManager.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("utils::account::formatAccountInfo() passes test"
          "(pass)",
          "[multi-file:2]")
{
    Account account{ "   Darth Vader   ", "1/01/2022", "911" };
    REQUIRE(utils::account::formatAccountInfo(account));
}

TEST_CASE("Account Manager isEligible() method returns false on initialization "
          "(pass)",
          "[multi-file:2]")
{
    AccountManager manager;
    REQUIRE(manager.isEligible() == false);
}
