#include "../include/bank.h"
#include "../include/account.h"

#include <cctype>
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
    std::string name{};
    unsigned int age{};
    unsigned int wallet{};
    unsigned int initialDeposit{};

    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter wallet cash: ";
    std::cin >> wallet;
    std::cout << "Enter initial deposit: ";
    std::cin >> initialDeposit;

    while ((initialDeposit > wallet) || (initialDeposit == 0))
    {
        std::cout << "\n";
        std::cout << "Incorrect deposit\n";
        std::cout << "Enter initial deposit again: ";
        std::cin >> initialDeposit;
    }

    Account account{ static_cast<std::string_view>(name), age, wallet };

    if (!account.isValid())
    {
        setup::getCorrectInput(&account);
    }

    std::cout << "\n";
    std::cout << "Account is valid!\n";

    Bank bank{};

    if (bank.createAccount(&account, initialDeposit))
    {
        std::cout << "Bank account created successfully!\n";
    }
    else
    {
        std::cout << "Could not create bank account\n";
    }

    std::cout << "Commands:\n";
    std::cout << "c        = Get wallet cash\n";
    std::cout << "s        = Get current savings\n";
    std::cout << "d <cash> = Deposit <cash> to bank\n";
    std::cout << "w <cash> = Withdraw <cash> from bank\n";
    std::cout << "q        = Quit program\n";

    bool prompt{ true };
    char command{};
    unsigned int cash{};

    // FIX: Broken input
    while (prompt)
    {
        std::cout << ">> ";
        std::cin >> command;

        switch (std::tolower(command))
        {
        case 'c':
            std::cout << "Cash in wallet: " << account.wallet << "\n";
            break;
        case 's':
            std::cout << "Current savings: " << bank.getSavings() << "\n";
            break;
        case 'd':
            std::cout << "Amount: ";
            std::cin >> cash;

            if (bank.deposit(cash))
            {
                std::cout << "Deposited " << cash << " to bank\n";
            }
            else
            {
                std::cout << "Failed to deposit cash\n";
            }
            break;
        case 'w':
            std::cout << "Amount: ";
            std::cin >> cash;

            if (bank.withdraw(cash))
            {
                std::cout << "Withdrawn " << cash << " from bank\n";
            }
            else
            {
                std::cout << "Failed to withdraw cash\n";
            }
            break;
        case 'q':
            prompt = false;
            break;
        default:
            std::cout << "Please provide a proper command\n";
            break;
        }
    }

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
