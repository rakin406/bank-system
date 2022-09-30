#include "../include/client.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Client::isWalletValid() returns correct boolean"
          "(pass)",
          "[multi-file:2]")
{
    Client client{};

    client.wallet = 0;
    REQUIRE(client.isWalletValid() == false);

    client.wallet = -1500;
    REQUIRE(client.isWalletValid() == false);

    client.wallet = 3000;
    REQUIRE(client.isWalletValid() == true);
}
