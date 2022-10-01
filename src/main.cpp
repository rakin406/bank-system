#include "../include/bank.h"
#include "../include/client.h"
#include "../include/setup.h"
#include "../include/utils.h"

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    int wallet{};
    int initialDeposit{};

    std::cout << "Enter wallet cash: ";
    std::cin >> wallet;

    Client client{ wallet };

    if (!client.isWalletValid())
    {
        setup::getCorrectInput(&client);
    }

    std::cout << "\n";
    std::cout << "Client is valid!\n";

    Bank bank{};

    std::cout << "Enter initial deposit: ";
    std::cin >> initialDeposit;

    while ((initialDeposit > wallet) || (initialDeposit <= 0))
    {
        std::cout << "\n";
        std::cout << "Incorrect deposit\n";
        std::cout << "Enter initial deposit again: ";
        std::cin >> initialDeposit;
    }

    if (bank.registerClient(&client, initialDeposit))
    {
        std::cout << "Client registered to bank successfully!\n";
    }
    else
    {
        std::cout << "Could not register client to bank\n";
    }

    setup::printCommands();

    bool prompt{ true };
    std::string command{};

    // FIX: Broken input
    while (prompt)
    {
        std::cout << ">> ";
        std::cin >> command;

        // Command input to lowercase
        utils::stringToLowerCase(&command);

        if (command == "c")
        {
            setup::printWallet(client);
        }
        else if (command == "s")
        {
            setup::printSavings(bank);
        }
        else if (command == "d")
        {
            setup::deposit(&bank);
        }
        else if (command == "w")
        {
            setup::withdraw(&bank);
        }
        else if (command == "da")
        {
            setup::depositAll(&bank);
        }
        else if (command == "wa")
        {
            setup::withdrawAll(&bank);
        }
        else if (command == "q")
        {
            prompt = false;
        }
        else
        {
            std::cout << "Please provide a proper command\n";
        }
    }

    return 0;
}
