#include "../include/bank.h"
#include "../include/account.h"

#include <iostream>
#include <string>
#include <string_view>

namespace setup
{
    /**
     * @brief Get input for account information until it's valid.
     *
     * @param account Client account.
     */
    void getCorrectInput(Account* account);
} // namespace setup

int main()
{
    Bank bank;

    std::string name{};
    unsigned int age{};
    int wallet{};

    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter wallet cash: ";
    std::cin >> wallet;

    Account account{ static_cast<std::string_view>(name), age, wallet };

    if (!account.isValid())
    {
        setup::getCorrectInput(&account);
    }

    std::cout << "Account is valid!\n";

    return 0;
}

void setup::getCorrectInput(Account* account)
{
    std::string name{};
    unsigned int age{};

    // Keep getting input until account is valid
    while (!account->isValid())
    {
        if (!account->isNameValid())
        {
            std::cout << "Invalid name\n";
            std::cout << "Enter name again: ";
            std::getline(std::cin >> std::ws, name);
        }
        else if (!account->isAgeValid())
        {
            std::cout << "Underage\n";
            std::cout << "Enter age again: ";
            std::cin >> age;
        }

        // Reset values
        account->name = name;
        account->age = age;
    }
}
