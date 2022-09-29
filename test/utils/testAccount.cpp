#include "../../include/utils/account.h"

#include <catch2/catch_test_macros.hpp>

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
