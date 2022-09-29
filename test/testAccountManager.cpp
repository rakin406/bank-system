#include "../include/accountManager.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("AccountManager::isEligible() method returns false on initialization "
          "(pass)",
          "[multi-file:3]")
{
    AccountManager manager;
    REQUIRE(manager.isEligible() == false);
}

TEST_CASE("AccountManage::getAccount() method returns account"
          "(pass)",
          "[multi-file:3]")
{
    AccountManager manager;
    Account account{ "Darth Vader", "", "" };
    manager.createAccount(account);
    REQUIRE(manager.getAccount() == account);
}
