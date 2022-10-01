#include "../include/utils.h"

#include <catch2/catch_test_macros.hpp>

#include <string>

TEST_CASE("\"   Hello World   \" is equal to \"Hello World\""
          "(pass)",
          "[multi-file:1]")
{
    REQUIRE(utils::trim("   Hello World   ") == "Hello World");
}

TEST_CASE("\"HELLO WORLD\" is equal to \"hello world\""
          "(pass)",
          "[multi-file:1]")
{
    std::string str{ "HELLO WORLD" };
    utils::stringToLowerCase(&str);
    REQUIRE(str == "hello world");
}
