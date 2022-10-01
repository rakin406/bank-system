#ifndef SETUP_H
#define SETUP_H

#include "bank.h"
#include "client.h"

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

    /**
     * @brief Print wallet cash.
     *
     * @param client Client.
     */
    void printWallet(const Client& client);

    // Bank input/output
    void printSavings(const Bank& bank);
    void deposit(Bank* bank);
    void withdraw(Bank* bank);
    void depositAll(Bank* bank);
    void withdrawAll(Bank* bank);
} // namespace setup

#endif
