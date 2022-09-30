#include "../include/bank.h"
#include "../include/client.h"
#include "../include/utils.h"

#include <iostream>
#include <string>
#include <string_view>

namespace setup
{
    /**
     * @brief Get input for client information until it's valid.
     *
     * @param client Client.
     */
    void getCorrectInput(Client* client);

    /**
     * @brief Print commands.
     */
    void printCommands();
} // namespace setup

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
    int cash{};

    // FIX: Broken input
    while (prompt)
    {
        std::cout << ">> ";
        std::cin >> command;

        // Command input to lowercase
        utils::stringToLowerCase(&command);

        if (command == "c")
        {
            std::cout << "Cash in wallet: " << client.wallet << "\n";
        }
        else if (command == "s")
        {
            std::cout << "Current savings: " << bank.getSavings() << "\n";
        }
        else if (command == "d")
        {
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
        }
        else if (command == "w")
        {
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
        }
        else if (command == "da")
        {
            if (bank.depositAll())
            {
                std::cout << "Deposited all cash to bank\n";
            }
            else
            {
                std::cout << "Failed to deposit cash\n";
            }
        }
        else if (command == "wa")
        {
            if (bank.withdrawAll())
            {
                std::cout << "Withdrawn all cash from bank\n";
            }
            else
            {
                std::cout << "Failed to withdraw cash\n";
            }
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

void setup::getCorrectInput(Client* client)
{
    int wallet{};

    // Keep getting input until wallet is valid
    while (!client->isWalletValid())
    {
        std::cout << "Invalid wallet cash\n";
        std::cout << "Enter wallet cash again: ";
        std::cin >> wallet;

        // Reset value
        client->wallet = wallet;
    }
}
void setup::printCommands()
{
    std::cout << "Commands:\n";
    std::cout << "c        = Get wallet cash\n";
    std::cout << "s        = Get current savings\n";
    std::cout << "d <cash> = Deposit <cash> to bank\n";
    std::cout << "w <cash> = Withdraw <cash> from bank\n";
    std::cout << "da       = Deposit all cash to bank\n";
    std::cout << "wa       = Withdraw all cash from bank\n";
    std::cout << "q        = Quit program\n";
}
