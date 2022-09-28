#include "../include/accountManager.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Account Manager isEligible() method returns false on initialization "
          "(pass)",
          "[multi-file:1]")
{
    AccountManager manager;
    REQUIRE(manager.isEligible() == false);
}
