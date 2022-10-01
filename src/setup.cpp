#include "../include/setup.h"

#include <iostream>

namespace setup
{
    void getCorrectInput(Client* client)
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

    void printCommands()
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

    void printWallet(const Client& client)
    {
        std::cout << "Cash in wallet: " << client.wallet << "\n";
    }

    void printSavings(const Bank& bank)
    {
        std::cout << "Current savings: " << bank.getSavings() << "\n";
    }

    void deposit(Bank* bank)
    {
        int cash{};
        std::cout << "Amount: ";
        std::cin >> cash;

        if (bank->deposit(cash))
        {
            std::cout << "Deposited " << cash << " to bank\n";
        }
        else
        {
            std::cout << "Failed to deposit cash\n";
        }
    }

    void withdraw(Bank* bank)
    {
        int cash{};
        std::cout << "Amount: ";
        std::cin >> cash;

        if (bank->withdraw(cash))
        {
            std::cout << "Withdrawn " << cash << " from bank\n";
        }
        else
        {
            std::cout << "Failed to withdraw cash\n";
        }
    }

    void depositAll(Bank* bank)
    {
        if (bank->depositAll())
        {
            std::cout << "Deposited all cash to bank\n";
        }
        else
        {
            std::cout << "Failed to deposit cash\n";
        }
    }

    void withdrawAll(Bank* bank)
    {
        if (bank->withdrawAll())
        {
            std::cout << "Withdrawn all cash from bank\n";
        }
        else
        {
            std::cout << "Failed to withdraw cash\n";
        }
    }
} // namespace setup
