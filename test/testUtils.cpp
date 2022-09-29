#include "../include/utils/utils.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("\"   Hello World   \" is equal to \"Hello World\""
          "(pass)",
          "[multi-file:1]")
{
    REQUIRE(utils::trim("   Hello World   ") == "Hello World");
}
